class DSU {
    public:
    std::unordered_map<string, string> parent; // second is a parent of first

    std::string find(std::string x){
        if (parent[x] == x) return x;

        return find(parent[x]);
    }

    void unite(std::string node_a, std::string node_b){
        std::string parent_a = find(node_a);
        std::string parent_b = find(node_b);

        // set a new relationship that parent_a's parent is parent_b
        // this can be optimized to ensure nodes of smaller ht get merged with larger one
        // purely to ensure the stack call size is lowered as part of future copy
        if (parent_a == parent_b) return; // need to think about this
        parent[parent_a] = parent_b;
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        /*
        Common Parent problem

        where Parent cannot be the Name of the Person - and it has to be email

        Every account has a parent and it could be itself

        Disjoint set union
        Simple
        Determine Parent to Account via their Emails

        Once the parents are established 

        Go through each email and re-establish groups indexed by the parent name
        Once we have a group by it's parent name
        return the Name of the person followed the sorted emails
        (Maintain an Lookup of Account to Name)
        */

        std::unordered_map<string, string> indexAccountToPersonName;
        DSU dsu;

        for (const auto& entry: accounts){
            const string person_name = entry[0];
            const string primary_account = entry[1];
            for (int i = 1; i < entry.size(); i++){
                string account = entry[i];
                
                indexAccountToPersonName[account] = person_name;
                if(!dsu.parent.contains(account))
                {
                    dsu.parent[account] = account; 
                    // instead of setting the account itself, we are setting this to
                    // one of the email of the account so far - let's use the first 
                    // account, since all accounts are expected to have atleast one email 
                    // dsu.parent[account] = primary_account;
                }

                dsu.unite(account, primary_account); // we know this relationhsip is valid
            }
        } // we optimize the node to "root" on every unite, we are recursively updating the parent relationships 
        // on every new update that is being established

        // dsu parent only contains the immediate relationships
        // it is through find that we idenitfy root

        std::unordered_map<string, std::vector<string>> new_accounts; // indexed by primary account(root)
        for (const auto& [node, _] : indexAccountToPersonName){
            new_accounts[dsu.find(node)].push_back(node); // if it does not exist we will create the pair and update the pair if an entry exists
        }

        std::vector<std::vector<std::string>> result;
        for (auto& [root, accounts] : new_accounts) {
            std::sort(accounts.begin(), accounts.end());
            
            std::string name = indexAccountToPersonName[root];

            std::vector<std::string> flattened_account;

            flattened_account.push_back(name);
            flattened_account.insert(flattened_account.end(), accounts.begin(), accounts.end());
            result.push_back(flattened_account);
        }

        return result;
        
    }
};