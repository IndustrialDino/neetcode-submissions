class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    /*
    getWordPatterns
     given a word - get its possible patterns 
     set_pattern<word>
     for i in size of word
        new_word = word
        new_word[i] = `#`
        set_pattern.insert(word[i])

     areWordsSeparatedByOneChar
        if word_a == word_b return false
        if any of word_a's patterns match with word_b's patterns return true
            for temp_a in getWordPatterns(word_a)
                for temp_b in getWordPatterns(word_b)
                    if temp_a == temp_b return true
        else false

    wordsList.push_back(beginWord) // warning: we are manipulating the input

    Setup Adjacency Graph
    adg_map<word, vector<word>>{}

    for (word_a in words){
        for (word_b in words){
         if(areWordsSeparatedByOneChar)
            adj_map[word_a].push_back(word_b)
        }
    }

    RUN BFS whil tracking visited nodes and degrees of separation

    visited_set<word>

    queue_words<std::pair<word, degree_separation>>

    queue_words.push(beginWord, 0)
    visited_set.insert(beginWord)


    while(!queue_words.empty()){
        next_word, d = queue_words.front()
        queue_words.pop()
        if next_word == endWord return d+1;
        for (neighor: adj_map[next_wor])
            if (neighbor is not visite)
                queue.push(neighhor, d +1)
    
    return 0;
    }
    */  
    
    return 0;
    }
};
