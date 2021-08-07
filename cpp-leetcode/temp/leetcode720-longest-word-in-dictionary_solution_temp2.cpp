#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

/* 39 / 59 test cases passed. */
class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.empty()) return "";
        
        map<string, int> dict;
        for (auto word : words)
        {
            if (isAllPrefixExist(word, words) && isSubstrCountMeet(word, words))
                dict.insert(make_pair(word, word.size()));
        }
        int maxLen = 0;
        for (auto kvp : dict)
        {
            if (kvp.second > maxLen) 
                maxLen = kvp.second;          
        }

        map<string, int> dict2;
        for (auto kvp : dict)
        {
            if (kvp.second == maxLen)
            {
                dict2.insert(make_pair(kvp.first, kvp.second));
            }            
        }        
        auto firstKvp = *std::next(dict2.begin(), 0);
        return firstKvp.first;
    }

    bool isAllPrefixExist(string theWord, vector<string> words)
    {
        int len = theWord.size();
        int containCount = 0;
        int i = len;
        while (i > 0)
        {
            if (find(words.begin(), words.end(), theWord.substr(0, i)) != words.end())
                containCount++;          
            i--;                
        }            
        return containCount == len;
    }

    bool isSubstrCountMeet(string theWord, vector<string> words)
    {
        int count = 0;
        bool hasFirstLetter = false;
        vector<string> numsWithLen;
        for (auto word : words)
        {
            if (word.size() == 1)
                numsWithLen.push_back(word);          
        }
        if (find(numsWithLen.begin(), numsWithLen.end(), theWord.substr(0, 1)) != numsWithLen.end())
            hasFirstLetter = true;

        for (auto word : words)
        {            
            if (theWord.find(word) != string::npos)
                count++;            
        }
        return hasFirstLetter && (count >= theWord.size());
    }
};

// Test
int main()
{
    Solution sol;
    // vector<string> words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    vector<string> words = { "cxkhcgbrleqmcdgafmukhijsctpsgz","cxkhcgbrleqmcdgafmukhijsctpssg","cxkhcgbrleqmcdgafmukhijsctpsha","cxkhcgbrleqmcdgafmukhijsctpsqw","cxkhcgbrleqmcdgafmukhijsctpsas","cxkhcgbrleqmcdgafmukhijsctpstf","cxkhcgbrleqmcdgafmukhijsctpsid","cxkhcgbrleqmcdgafmukhijsctpsau","cxkhcgbrleqmcdgafmukhijsctpsdj","cxkhcgbrleqmcdgafmukhijsctpssb","cxkhcgbrleqmcdgafmukhijsctpsma","cxkhcgbrleqmcdgafmukhijsctpssl","cxkhcgbrleqmcdgafmukhijsctpsgy","cxk","cxkhcgbrleqmcdgafmukhijsctpsua","cxkhcgbrleqmcdgafmukhijsctpsyb","cxkhcgbrleqmcdgafmukhijsctpsgf","cxkhcgbrleqmcdgafmukhijsctpszn","cxkhcgbrleqmcdgafmukhijsctpsch","cxkhcgbrleqmcdgafmukhijsctpsrb","cxkhcgbrleqmcdgafmukhijsctpsnp","cxkhcgbrleqmcdgafmukhijsctpscy","cxkhcgbrleqmcdgafmukhijsctpsjp","cxkhcgbrleqmcdgafmukhijsctpsjo","cxkhcgbrleqmcdgafmukhijsctpsbb","cxkhcgbrleqmcdgafmukhijsc","cxkhcgbrleqmcdgafmukhijsctpsuj","cxkhcgbrleqmcdgafmukhijsctpsaz","cxkhcgbrleq","cxkhcgbrleqmcdgafmukhijsctpsdw","cxkhcgbrleqmcdgafmukhijsctpsnk","cxkhcgbrleqmcdgafmukhijsctpszk","cxkhcgbrleqmcdgafmukhijsctpswt","cxkhcgbrleqmcdgafmukhijs","cxkhcgbrleqmcdgafmukhijsctpshx","cxkhcgbrleqmcdgafmukhijsctpszt","cxkhcgbrleqmcdgafmukhijsctpsfr","cxkhcgbrleqmcdgafmukhijsctpspa","cxkhcgbrleqmcdgafmukhijsctpsbs","cxkhcgbrleqmcdgafmukhijsctpsxt","cxkhcgbrleqmcdgafmukhijsctpsyk","cxkhcgbrleqmcdgafmukhijsctpsra","cxkhcgbrleqmcdgafmukhijsctpssh","cxkhcgbrleqmcdgafmukhijsctpsj","cxkhcgbrleqmcdgafmukhijsctpsnd","cxkhcgbrleqmcdgafmukhijsctpsrr","cxkhcgbrleqmcdgafmukhijsctpslw","cxkhcgbrleqmcdgafmukhijsctpsnc","cxkhcgbrleqmcdgafmukhijsctpsih","cxkhcgbrleqmcdgafmukhijsctpslx","cxkhcgbrleqmcdgafmukhijsctpsvf","cxkhcgbrleqmcdgafmukhijsctpstl","cxkhcgbrleqmcdgafmukhijsctpssw","cxkhcgbrleqmcdgafmukhijsctpsle","cxkhcgbrleqmcdgafmukhijsctpspo","cxkhcgbrleqmcdgafmukhijsctpsrw","cxkhcgbrleqmcdgafmukhijsctpsxc","cxkhcgbrleqmcdgafmukhijsctpsrq","cxkhcgbrleqmcdgafmuk","cxkhcgbrleqmcdgafmukhijsctpsla","cxkhcgbrleqmcdgafmukhijsctpsgc","cxkhcgbrleqmcdgafmukhijsctpsay","cxkhcgbrleqmcdgafmukhijsctpscb","cxkhcgbrleqmcdgafmukhijsctpsaj","cxkhcgbrleqmcdgafmu","cxkhcgbrleqmcdgafmukhijsctpsgj","cxkhcgbrleqmcdgafmukhijsctpspl","cxkhcgbrleqmcdgafmukhijsctpsvz","cxkhc","cxkhcgbrleqmcdgafmukhijsctpsji","cxkhcgbrleqmcdgafmukhijsctpsjl","cxkhcgbrleqmcdgafmukhijsctpsef","cxkhcgbrleqmcdgafmukhijsctpsyi","cxkhcgbrleqmcdgafmukhijsctpsqa","cxkhcgbrleqmcdgafmukhijsctpszd","cxkhcgbrleqmcdgafmukhijsctpsyg","cxkhcgbrleqmcdgafmukhijsctpsbn","cxkhcgbrleqmcdgafmukhijsctpsfm","cxkhcgbrleqmcdgafmukhijsctpsuz","cxkhcgbrleqmcdgafmukhijsctpss","cxkhcgbrleqmcdgafmukhijsctpscp","cxkhcgbrleqmcdgafmukhijsctpsgg","cxkhcgb","cxkhcgbrleqmcdgafmukhijsctpskw","cxkhcgbrleqmcdgafmukhijsctpsky","cxkhcgbrleqmcdgafmukhijsctpswz","cxkhcgbrleqmcdgafmukhijsctpsdn","cxkhcgbrleqmcdgafmukhijsctpsjd","cxkhcgbrleqmcdgafmukhijsctpstz","cxkhcgbrleqmcdgafmukhijsctpspu","cxkhcgbrleqmcdgafmukhijsctpsxb","cxkhcgbrleqmcdgafmukhijsctpsum","cxkhcgbrleqmcdgafmukhijsctpsot","cxkhcgbrleqmcdgafmukhijsctpszs","cxkhcgbrleqmcdgafmukhijsctpscj","cxkhcgbrleqmcdgafmukhijsctpspt","cxkhcgbrleqmcdgafmukhijsctpsgr","cxkhcgbrleqmcdgafmukhijsctpsuv","cxkhcgbrleqmcdgafmukhijsctpsfj","cxkhcgbrleqmcdgafmukhijsctpssz","cxkhcgbrleqmcdgafmukhijsctpsyd","cxkhcgbrleqmcdgafmukhijsctpsfs","cxkhcgbrleqmcdgafmukhijsctpsae","cxkhcgbrleqmcdgafmukhijsctpsli","cxkhcgbrleqmcdgafmukhijsctpswn","cxkhcgbrleqmcdgafmukhijsctpscv","cxkhcgbrleqmcdgafmukhijsctpsxo","cxkhcgbrleqmcdgafmukhijsctpsjn","cxkhcgbrleqmcdgafmukhijsctpsnb","cxkhcgbrleqmcdgafmukhijsctpsur","cxkhcgbrleqmcdgafmukhijsctpsrc","c","cxkhcgbrleqmcdgafmukhijsctpsdl","cxkhcgbrleqmcdgafmukhijsctpsie","cxkhcgbrleqmcdgafmukhijsctpsvn","cxkhcgbrleqmcdgafmukhijsctpsfc","cxkhcgbrleqmcdgafmukhijsctpski","cxkhcgbrleqmcdgafmukhijsctpsic","cxkhcgbrleqmcdgafmukhijsctpsff","cxkhcgbrleqmcdgafmukhijsctpsui","cxkhcgbrleqmcdgafmukhijsctpsvw","cxkhcgbrleqmcdgafmukhijsctpskc","cxkhcgbrleqmcdgafmukhijsctpstx","cxkhcgbrleqmcdgafmukhijsctpsri","cxkhcgbrleqmcdgafmukhijsctpsqn","cxkhcgbrleqmcdgafmukhijsctpsdv","cxkhcgbrleqmcdgafmukhijsctpsds","cxkhcgbrleqmcdgafmukhijsctpsvg","cxkhcgbrleqmcdgafmukhijsctpscd","cxkhcgbrleqmcdgafmukhijsctpswe","cxkhcgbrleqmcdgafmukhijsctpsib","cxkhcgbrleqmcdgafmukhijsctpsuc","cxkhcgbrleqmcdgafmukhijsctpsxi","cxkhcgbrleqmcdgafmukhijsctpspz","cxkhcgbrleqmcdgafmukhijsctpsdc","cxkhcgbrleqmcdgafmukhijsctpszr","cxkhcgbrleqmcdgafmukhijsctpshe","cxkhcgbrleqmcdgafmukhijsctpsh","cxkhcgbrleqmcdgafmukhijsctpsxs","cxkhcgbrleqmcdgafmukhijsctpsto","cxkhcgbrleqmcdgafmukhijsctpsws","cxkhcgbr","cxkhcgbrleqmcdgafmukhijsctpssa","cxkhcgbrleqmcdgafmukhijsctpswv","cxkhcgbrleqmcdgafmukhijsctpsgn","cxkhcgbrleqmcdgafmukhijsctpsao","cxkhcgbrleqmcdgafmukhijsctpszm","cxkhcgbrleqmcdgafmukhijsctpsva","cxkhcgbrleqmcdgafmukhijsctpsgh","cxkhcgbrleqmcdgafmukhijsctpsip","cxkhcgbrleqmcdgafmukhijsctpsgs","cxkhcgbrleqmcdgafmukhijsctpsxz","cxkhcgbrleqmcdga","cxkhcgbrleqmcdgafmukhijsctpseg","cxkhcgbrleqmcdgafmukhijsctpsku","cxkhcgbrleqmcdgafmukhijsctpsdz","cxkhcgbrleqmcdgafmukhijsctpsso","cxkhcgbrleqmcdgafmukhijsctpshw","cxkhcgbrleqmcdgafmukhijsctpsou","cxkhcgbrleqmcdgafmukhijsctpssc","cxkhcgbrleqmcdgafmukhijsctpsrj","cxkhcgbrleqmcdgafmukhijsctpset","cxkhcgbrleqmcdgafmukhijsctpscr","cxkhcgbrleqmcdgafmukhijsctpsya","cxkhcgbrleqmcdgafmukhijsctpsej","cxkhcgbrleqmcdgafmukhijsctpsub","cxkhcgbrleqmcdgafmukhijsctpszx","cxkhcgbrleqmcdgafmukhijsctpsxq","cxkh","cxkhcgbrleqmcdgafmukhijsctpsdu","cxkhcgbrleqmcdgafmukhijsctpsw","cxkhcgbrleqmcdgafmukhijsctpseq","cxkhcgbrleqmcdgafmukhijsctpsxn","cxkhcgbrleqmcdgafmukhijsctpswr","cxkhcgbrleqmcdgafmukhijsctpszv","cxkhcgbrleqmcdgafmukhijsctpsjc","cxkhcgbrleqmcdgafmukhijsctpspi","cxkhcgbrleqmcdgafmukhijsctpspg","cxkhcgbrleqmcdgafmukhijsctpsbt","cxkhcgbrleqmcdgafmukhijsctpsdt","cxkhcgbrleqmcdgafmukhijsctpsdg","cxkhcgbrleqmcdgafmukhijsctpsmb","cxkhcgbrleqmcdgafmukhijsctpsgo","cxkhcgbrleqmcdgafmukhijsctpsfb","cxkhcgbrleqmcdgafmukhijsctpska","cxkhcgbrleqmcdgafmukhijsctpslq","cxkhcgbrleqmcdgafmukhijsctpsi","cxkhcgbrleqmcdgafmukhijsctpstw","cxkhcgbrleqmcdgafmukhijsctpspx","cxkhcgbrleqmcdgafmukhijsctpspe","cxkhcgbrleqmcdgafmukhijsctpspp","cxkhcgbrleqmcdgafmukhijsctpsbh","cxkhcgbrleqmcdgafmukhijsctpsbf","cxkhcgbrleqmcdgafmukhijsctpsuy","cxkhcgbrleqmcdgafmukhijsctpsey","cxkhcgbrleqmcdgafmukhijsctpsy","cxkhcgbrleqmcdgafmukhijsctpsgu","cxkhcgbrleqmcdgafmukhijsctpsmc","cxkhcgbrleqmcdgafmukhijsctpsbr","cxkhcgbrleqmcdgafmukhijsctpsmy","cxkhcgbrleqmcdgafmukhijsctpsps","cxkhcgbrleqmcdgafmukhijsctpsfq","cxkhcgbrleqmcdgafmukhijsctpsxe","cxkhcgbrleqmcdgafmukhijsctpszc","cxkhcgbrleqmcdgafmukhijsctpsyt","cxkhcgbrleqmcdgafmukhijsctpsut","cxkhcgbrleqmcdgafmukhijsctpshm","cxkhcgbrleqmcdgafmukhijsctpstn","cxkhcgbrleqmcdgafmukhijsctpsll","cxkhcgbrleqmcdgafmukhijsctpsfu","cxkhcgbrleqmcdgafmukhijsctpsbq","cxkhcgbrleqmcdgafmukhijsctpsgt","cxkhcgbrleqmcdgafmukhijsctpsuf","cxkhcgbrleqmcdgafmukhijsctpsjf","cxkhcgbrleqmcdgafmukhijsctpsuq","cxkhcgbrleqmcdgafmukhijsctpse","cxkhcgbrleqmcdgafmukhijsctpskb","cxkhcgbrleqmcdgafmukhijsctpsml","cxkhcgbrleqmcdgafmukhijsctpsnu","cxkhcgbrleqmcdgafmukhijsctpsco","cxkhcgbrleqmcdgafmukhijsctpsxw","cxkhcgbrleqmcdgafmukhijsctpsfo","cxkhcgbrleqmcdgafmukhijsctpsdr","cxkhcgbrleqmcdgafmukhijsctpsfz","cxkhcgbrleqmcdgafmukhijsctpsza","cxkhcgbrleqmcdgafmukhijsctpsnf","cxkhcgbrleqmcdgafmukhijsctpscu","cxkhcgbrleqmcdgafmukhijsctpsoa","cxkhcgbrleqmcdgafmukhijsctpsqr","cxkhcgbrleqmcdgafmukhijsctpsgb","cxkhcgbrleqmcdgafmukhijsctpshd","cxkhcgbrl","cxkhcgbrleqmcdgafmukhijsctpsik","cxkhcgbrleqmcd","cxkhcgbrleqmcdgafmukhijsctpser","cxkhcgbrleqmcdgafmukhijsctpscq","cxkhcgbrleqmcdgafmukhijsctpsvv","cxkhcgbrleqmcdgafmukhijsctpsrm","cxkhcgbrleqmcdgafmukhijsctpstq","cxkhcgbrleqmcdgafmukhijsctpsvo","cxkhcgbrleqmcdgafmukhijsctpspn","cxkhcgbrleqmcdgafmukhijsctpseo","cxkhcgbrleqmcdgafmukhijsctpsm","cxkhcgbrleqmcdgafmukhijsctpsix","cxkhcgbrleqmcdgafmukhijsctpsil","cxkhcgbrleqmcdgafmukhijsctpsif","cxkhcgbrleqmcdgafmukhijsctpsuk","cxkhcgbrleqmcdgafmukhijsctpsjt","cxkhcgbrleqmcdgafmukhijsctpsms","cxkhcgbrleqmcdgafmukhijsctpsyn","cxkhcgbrleqmcdgafmukhijsctpslm","cxkhcgbrleqmcdgafmukhijsctpstb","cxkhcgbrleqmcdgafmukhijsctpsuh","cxkhcgbrleqmcdgafmukhijsctpsmk","cxkhcgbrleqmcdgafmukhijsctpsyx","cxkhcgbrleqmcdgafmukhijsctpszp","cxkhcgbrleqmcdgafmukhijsctpsdd","cxkhcgbrleqmcdgafmukhijsctpsex","cxkhcgbrleqmcdgafmukhijsctpsny","cxkhcgbrleqmcdgafmukhijsctpsdm","cxkhcgbrleqmcdgafmukhijsctpshc","cxkhcgbrleqmcdgafmukhijsctpspj","cxkhcgbrleqmcdgafmukhijsctpsug","cxkhcgbrleqmcdgafmukhijsctpsew","cxkhcgbrleqmcdgafmukhijsctpswg","cxkhcgbrleqmcdgafmukhijsctpsko","cxkhcgbrleqmcdgafmukhijsctpsmj","cxkhcgbrleqmcdgafmukhijsctpsdp","cxkhcgbrleqmcdgafmukhijsctpsro","cxkhcgbrleqmcdgafmukhijsctpsci","cxkhcgbrleqmcdgafmukhijsctpsyu","cxkhcgbrleqmcdgafmukhijsctpscc","cxkhcgbrleqmcdgafmukhijsctpstk","cxkhcgbrleqmcdgafmukhijsctpsld","cxkhcgbrleqmcdgafmukhijsctpsnw","cxkhcgbrleqmcdgafmukhijsctpsz","cxkhcgbrleqmcdgafmukhijsctpsqp","cxkhcgbrleqmcdgafmukhijsctpshp","cxkhcgbrleqmcdgafmukhijsctpsbc","cxkhcgbrleqmcdgafmukhijsctpsmq","cxkhcgbrleqmcdgafmukhijsctpsys","cxkhcgbrleqmcdgafmukhijsctpsbd","cxkhcgbrleqmcdgafmukhijsctpsav","cxkhcgbrleqmcdgafmukhijsctpswi","cxkhcgbrleqmcdgafmukhijsctpsqi","cxkhcgbrleqmcdgafmukhijsctpsqc","cxkhcgbrleqmcdgafmukhijsctpsak","cxkhcgbrleqmcdgafmukhijsctpsah","cxkhcgbrleqmcdgafmukhijsctpscg","cxkhcgbrleqmcdgafmukhijsctpsfi","cxkhcgbrleqmcdgafmukhijsctpswc","cxkhcgbrleqmcdgafmukhijsctpskd","cxkhcgbrleqmcdgafmukhijsctpsjv","cxkhcgbrleqmcdgafmukhijsctpsgi","cxkhcgbrleqmcdgafmukhijsctpsus","cxkhcgbrleqmcdgafmukhijsctpsbl","cxkhcgbrleqmcdgafmukhijsctpsvk","cxkhcgbrleqmcdgafmukhijsctpsqf","cxkhcgbrleqmcdgafmukhijsctpslj","cxkhcgbrleqmcdgafmukhijsctpszz","cxkhcgbrleqmcdgafmukhijsctpsx","cxkhcgbrleqmcdgafmukhijsctpsxf","cxkhcgbrleqmcdgafmukhijsctpsyr","cxkhcgbrleqmcdgafmukhijsctpsve","cxkhcgbrleqmcdgafmukhijsctpseb","cxkhcgbrleqmcdgafmukhijsctpszy","cxkhcgbrleqmcdgafmukhijsctpsmh","cxkhcgbrleqmcdgafmukhijsctpsa","cxkhcgbrleqmcdgafmukhijsctpsmm","cxkhcgbrleqmcdgafmukhijsctpspw","cxkhcgbrleqmcdgafmukhijsctpsce","cxkhcgbrleqmcdgafmukhijsctpsyc","cxkhcgbrleqmcdgafmukhijsctpssu","cxkhcgbrleqmcdgafmukhijsctpsdi","cxkhcgbrleqmcdgafmukhijsctpsmp","cxkhcgbrleqmcdgafmukhijsctpsiq","cxkhcgbrleqmcdgafmukhijsctpsvj","cxkhcgbrleqmcdgafmukhijsctpszq","cxkhcgbrleqmcdgafmukhijsctpsrx","cxkhcgbrleqmcdgafmukhijsctpson","cxkhcgbrleqmcdgafmukhijsctpskk","cxkhcgbrleqmcdgafmukhijsctpskp","cxkhcgbrleqmcdgafmukhijsctpsow","cxkhcgbrleqmcdgafmukhijsctpsr","cxkhcgbrleqmcdgafmukhijsctpsne","cxkhcgbrleqmcdgafmukhijsctpsqx","cxkhcgbrleqmcdgafmukhijsctpskf","cxkhcgbrleqmcdgafmukhijsctpssr","cxkhcgbrleqmcdgafmukhijsctpsgv","cxkhcgbrleqmcdgafmukhijsctpsaw","cxkhcgbrleqmcdgafmukhijsctpsv","cxkhcgbrleqmcdgafmukhijsctpsmx","cxkhcgbrleqmcdgafmukhijsctpsmg","cxkhcgbrleqmcdgafmukhijsctpsag","cxkhcgbrleqmcdgafmukhijsctpssy","cxkhcgbrleqmcdgafmukhijsctpsfe","cxkhcgbrleqmcdgafmukhijsctpsev","cxkhcgbrleqmcdgafmukhijsctpskq","cxkhcgbrleqmcdgafmukhijsctpscz","cxkhcgbrleqmcdgafmukhijsctpstm","cxkhcgbrleqmcdgafmukhijsctpsxy","cxkhcgbrleqmcdgafmukhijsctpsio","cxkhcgbrleqmcdgafmukhijsctpsan","cxkhcgbrleqmcdgafmukhijsctpsu","cxkhcgbrleqmcdgafmukhijsctpsnn","cxkhcgbrleqmcdgafmukhijsctpsno","cxkhcgbrleqmcdgafmukhijsctpsaf","cxkhcgbrleqmcdgafmukhijsctpswq","cxkhcgbrleqmcdgafmukhijsctpsoj","cxkhcgbrleqmcdgafmukhijsctpsd","cxkhcgbrleqmcdgafmukhijsctpsvd","cxkhcgbrleqmcdgafmukhijsctpsqe","cxkhcgbrleqmcdgafmukhijsctpsru","cxkhcgbrleqmcdgafmukhijsctpsyj","cxkhcgbrleqmcdgafmukhijsctpsju","cxkhcgbrleqmcdgafmukhijsctpsjh","cxkhcgbrleqmcdgafmukhijsctpsvm","cxkhcgbrleqmcdgafmukhijsctpsis","cxkhcgbrleqmcdgafmukhijsctpsue","cxkhcgbrleqmcdgafmukhijsctpsni","cxkhcgbrleqmcdgafmukhijsctpstr","cxkhcgbrleqmcdgafmukhijsctpsfd","cxkhcgbrleqmcdgafmukhijsctpsop","cxkhcgbrleqmcdgafmukhijsctpslk","cxkhcgbrleqmcdgafmukhijsctpsep","cxkhcgbrleqmcdgafmukhijsctpsjb","cxkhcgbrleqmcdgafmukhijsctpszg","cxkhcgbrleqmcdgafmukhijsctpscw","cxkhcgbrleqmcdgafmukhijsctpsul","cxkhcgbrleqmcdgafmukhijsctpssi","cxkhcgbrleqmcdgafmukhijsctpsja","cxkhcgbrleqmcdgafmukhijsctpszb","cxkhcgbrleqmcdgafmukhijsctpsge","cxkhcgbrleqmcdgafmukhijsctpsme","cxkhcgbrleqmcdgafmukhijsctpsvq","cxkhcgbrleqmcdgafmukhijsctpsnx","cxkhcgbrleqmcdgafmukhijsctpsfh","cxkhcgbrleqmcdgafmukhijsctpsn","cxkhcgbrleqmcdgafmukhijsctpsmv","cxkhcgbrleqmcdgafmukhijsctpsvx","cxkhcgbrleqmcdgafmukhijsctpsor","cxkhcgbrleqmcdgafmukhijsctpsaq","cxkhcgbrleqmcdgafmukhijsctpswl","cxkhcgbrleqmcdgafmukhijsctpsbo","cx","cxkhcgbrleqmcdgafmukhijsctpswf","cxkhcgbrleqmcdgafmukhijsctpst","cxkhcgbrleqmcdgafmukhijsctpsl","cxkhcgbrleqmcdgafmukhijsctpsqh","cxkhcgbrleqmcdgafmukhijsctpskv","cxkhcgbrleqmcdgafmukhijsctpsbe","cxkhcgbrleqmcdgafmukhijsctpswm","cxkhcgbrleqmcdgafmukhijsctpsxu","cxkhcgbrleqmcdgafmukhijsctpsqu","cxkhcgbrleqmcdgafmukhijsctpsjg","cxkhcgbrleqmcdgafmukhijsctpsoe","cxkhcgbrleqmcdgafmukhijsctpso","cxkhcgbrleqmcdgafmukhijsctpsbx","cxkhcgbrleqmcdgafmukhijsctps","cxkhcgbrleqmcdgafmukhijsctpsby","cxkhcgbrleqmcdgafmukhijsctpsvi","cxkhcgbrleqmcdgafmukhijsctpsoq","cxkhcgbrleqmcdgafmukhijsctpsdk","cxkhcgbrleqmcdgafmukhijsctpsim","cxkhcgbrleqmcdgafmukhijsctpspq","cxkhcgbrleqmcdgafmukhijsctpsf","cxkhcgbrleqmcdgafmukhijsctpsfk","cxkhcgbrleqmcdgafmukhijsctpsq","cxkhcgbrleqmcdgafmukhijsctpsfa","cxkhcgbrleqmcdgafmukhijsctpswy","cxkhcgbrleqmcdgafmukhijsctpslh","cxkhcgbrleqmcdgafmukhijsctpsxk","cxkhcgbrleqmcdgafmukhijsctpslc","cxkhcgbrleqmcdgafmukhijsctpsyp","cxkhcgbrleqmcdgafmukhijsctpsts","cxkhcgbrleqmcdgafmukhijsctpshg","cxkhcgbrleqmcdgafmukhijsctpsyf","cxkhcgbrleqmcdgafmukhijsctpsup","cxkhcgbrleqmcdgafmukhijsctpshj","cxkhcgbrleqmcdgafmukhijsctpsbj","cxkhcgbrleqmcdgafmukhijsctpssq","cxkhcgbrleqmcdgafmukhijsctpssm","cxkhcgbrleqmcdgafmukhijsctpskz","cxkhcgbrleqmcdgafmukhijsctpspd","cxkhcgbrleqmcdgafmukhijsctpsyh","cxkhcgbrleqmcdgafmukhijsctpsg","cxkhcgbrleqmcdgafmukhijsctpswo","cxkhcgbrleqmcdgafmukhijsctpshq","cxkhcgbrleqmcdgafmukhijsctpsjw","cxkhcgbrleqmcdgafmukhijsctpsgq","cxkhcgbrleqmcdgafmukhijsctpscf","cxkhcgbrleqmcdgafmukh","cxkhcgbrleqmcdgafmukhijsctpsrf","cxkhcgbrleqmcdgafmukhijsctp","cxkhcgbrleqmcdgafmukhijsctpshk","cxkhcgbrleqmcdgafmukhijsctpsrl","cxkhcgbrleqmcdgafmukhijsctpsuw","cxkhcgbrleqmcdgafmukhijsctpsnt","cxkhcgbrleqmcdgafmukhijsctpsrz","cxkhcgbrleqmcdgafmukhijsctpsia","cxkhcgbrleqmcdgafmukhijsctpsk","cxkhcgbrleqmcdgafmukhijsctpsmo","cxkhcgbrleqmcdgafmukhijsctpslp","cxkhcgbrleqmcdgafmukhijsctpsfn","cxkhcgbrleqmcdgafmukhijsctpsgm","cxkhcgbrleqmcdgafmukhijsctpsei","cxkhcgbrleqmcdgafmukhijsctpsai","cxkhcgbrleqmcdgafmukhijsctpsom","cxkhcgbrleqmcdgafmukhijsctpsvb","cxkhcgbrleqmcdgafmukhijsctpslf","cxkhcgbrleqmcdgafmukhijsctpsbz","cxkhcgbrleqmcdgafmukhijsctpsbm","cxkhcgbrleqmcdgafmukhijsctpspr","cxkhcgbrleqmcdgafmukhijsctpsxl","cxkhcgbrleqmcdgafmukhijsctpsgw","cxkhcgbrleqmcdgafmukhijsctpsqy","cxkhcgbrleqmcdgafmukhijsctpsmd","cxkhcgbrleqmcdgafmukhijsctpsel","cxkhcgbrleqmcdgafmukhijsctpsrt","cxkhcgbrleqmcdgafmukhijsctpskm","cxkhcgbrleqmcdgafmukhijsctpswj","cxkhcgbrleqmcdgafmukhijsctpsns","cxkhcgbrleqmcdgafmukhijsctpsc","cxkhcgbrleqmcdgafmukhijsctpsij","cxkhcgbrleqmcdgafmukhijsctpsvu","cxkhcgbrleqmcdgafmukhijsctpsud","cxkhcgbrleqmcdgafmukhijsctpskx","cxkhcgbrleqmcdgafmukhijsctpsgx","cxkhcgbrleqmcdgafmukhijsctpsiu","cxkhcgbrleqmcdgafmukhijsctpsti","cxkhcgbrleqmcdgafmukhijsctpsqd","cxkhcgbrleqmcdgafmukhijsctpslr","cxkhcgbrleqmcdgafmukhijsctpsdh","cxkhcgbrleqmcdgafmukhijsctpswd","cxkhcgbrleqmcdgafmukhijsctpspb","cxkhcgbrleqmcdgafmukhijsctpsdb","cxkhcgbrleqmcdgafmukhijsctpsvh","cxkhcgbrleqmcdgafmukhijsctpssd","cxkhcgbrleqmcdgafmukhijsctpsap","cxkhcgbrleqm","cxkhcgbrleqmcdgafmukhijsctpsbu","cxkhcgbrleqmcdgafmukhijsctpsiw","cxkhcgbrleqmcdgafmukhijsctpsb","cxkhcgbrleqmcdgafmukhijsctpsoi","cxkhcgbrleqmcdgafmukhijsctpsmn","cxkhcgbrleqmcdgafmukhijsctpsux","cxkhcgbrleqmcdgafmukhijsctpsft","cxkhcgbrleqmcdgafmukhijsctpsgl","cxkhcgbrleqmcdgafmukhijsctpsye","cxkhcgbrleqmcdgafmukhijsctpsqo","cxkhcgbrleqmcdgafmukhijsctpsss","cxkhcgbrleqmcdgafmukhijsctpsrv","cxkhcgbrleqmcdgafmukhijsctpswh","cxkhcgbrleqmcdgafmukhijsctpsee","cxkhcgbrleqmcdgafmukhijsctpsty","cxkhcgbrleqmcdgafmukhijsctpsym","cxkhcgbrleqmcdgafmukhijsctpshi","cxkhcgbrleqmcdgafmukhijsctpsit","cxkhcgbrleqmcdgafmukhijsctpsam","cxkhcgbrleqmcdgafmukhijsctpsgd","cxkhcgbrleqmcdgafmukhijsctpstv","cxkhcgbrleqmcdgafmukhijsctpshh","cxkhcgbrleqmcdgafmukhijsctpsho","cxkhcgbrleqmcdgafmukhijsctpsmw","cxkhcgbrleqmcdgafmukhijsctpsse","cxkhcgbrleqmcdgafmukhijsctpsgp","cxkhcgbrleqmcdgafmukhijsctpsqt","cxkhcgbrleqmcdgafmukhijsctpsgk","cxkhcgbrleqmcdgafmukhijsctpsga","cxkhcgbrleqmcdgafmukhijsctpstj","cxkhcgbrleqmcdgafmukhijsctpsyq","cxkhcgbrleqmcdgafmukhijsctpsox","cxkhcgbrleqmcdgafmukhijsctpsuo","cxkhcgbrleqmcdgafmukhijsctpswb","cxkhcgbrleqmcdgafmukhijsctpscm","cxkhcgbrleqmcdgafmukhijsctpseu","cxkhcgbrleqmcdgafmukhijsctpsmr","cxkhcgbrleqmcdgafmukhijsctpsog","cxkhcgbrleqmcdgafmukhijsctpscs","cxkhcgbrleqmcdgafmukhijsctpseh","cxkhcgbrleqmcdgafmukhijsctpsjq","cxkhcgbrleqmcdgafmukhijsctpsvs","cxkhcgbrleqmcdgafmukhijsctpsat","cxkhcgbrleqmcdgafmukhijsctpstd","cxkhcgbrleqmcdgafmukhijsctpsok","cxkhcgbrleqmcdgafmukhijsctpswp","cxkhcgbrleqmcdgafmukhijsctpssx","cxkhcgbrleqmcdgafmukhijsctpsyy","cxkhcgbrleqmcdgafmukhijsctpsab","cxkhcgbrleqmcdgafmukhijsctpsxp","cxkhcgbrleqmcdgafmukhijsctpsqk","cxkhcgbrleqmcdgafmukhijsctpsrp","cxkhcgbrleqmcdgafmukhijsctpsmf","cxkhcgbrleqmcdgafmukhijsctpsnv","cxkhcgbrleqmcdgafmukhijsctpsls","cxkhcgbrleqmcdgafmukhijsctpsal","cxkhcgbrleqmcdgafmukhijsctpsnl","cxkhcgbrleqmcdgafmukhijsctpswu","cxkhcgbrleqmcdgafmukhijsctpsmu","cxkhcgbrleqmcdgafmukhijsctpsyz","cxkhcgbrleqmcdgafmukhijsctpstp","cxkhcgbrleqmcdgafmukhijsctpshf","cxkhcgbrleqmcdgafmukhijsctpszl","cxkhcgbrleqmcdgafmukhijsctpsob","cxkhcgbrleqmcdgafmukhijsctpsp","cxkhcgbrleqmcdgafmukhijsctpsvl","cxkhcgbrleqmcdgafmukhij","cxkhcgbrleqmcdgafmukhijsctpsek","cxkhcgbrleqmcdgafmukhijsctpsrd","cxkhcgbrleqmcdgafmukhijsctpsly","cxkhcgbrleqmcdgafmukhijsctpsxg","cxkhcgbrleqmcdgafmukhijsctpszw","cxkhcgbrleqmcdgafmukhijsctpszi","cxkhcgbrleqmcdgafmukhijsctpsqv","cxkhcgbrleqmcdgafmukhijsctpsed","cxkhcgbrleqmcdgaf","cxkhcgbrleqmcdgafmukhijsctpsjy","cxkhcgbrleqmcdgafmukhijsctpsfw","cxkhcgbrleqmcdgafmukhijsctpsun","cxkhcgbrleqmcdgafmukhijsctpsyl","cxkhcgbrleqmcdgafmukhijsctpszh","cxkhcgbrleqmcdgafmukhijsctpsec","cxkhcgbrleqmcdgafmukhijsctpskr","cxkhcgbrleqmcdgafmukhijsctpsxh","cxkhcgbrleqmcdgafmukhijsctpspm","cxkhcgbrleqmcdgafmukhijsctpshr","cxkhcgbrleqmcdgafmukhijsctpsoh","cxkhcgbrleqmcdgafmukhijsctpsvc","cxkhcgbrleqmcdgafmukhijsctpsir","cxkhcgbrleqmcdgafmukhijsctpsvy","cxkhcgbrleqmcdgafmukhijsctpsyw","cxkhcgbrleqmc","cxkhcgbrleqmcdgafmukhijsctpsnh","cxkhcgbrleqmcdgafmukhijsctpsvr","cxkhcgbrleqmcdgafmukhijsctpspc","cxkhcgbrleqmcdgafmukhijsctpsfy","cxkhcgbrleqmcdgafmukhijsctpsna","cxkhcgbrleqmcdgafmukhijsctpsiy","cxkhcgbrleqmcdgafmukhijsctpsnz","cxkhcgbrleqmcdgafmukhijsctpsfl","cxkhcgbrleqmcdgafmukhijsctpsbp","cxkhcgbrleqmcdgafmukhijsctpshz","cxkhcgbrleqmcdgafmukhijsctpswa","cxkhcgbrleqmcdgafmukhijsctpskt","cxkhcgbrleqmcdgafmukhijsctpsbi","cxkhcgbrleqmcdgafmukhijsctpshl","cxkhcgbrleqmcdgafmukhijsctpscn","cxkhcgbrleqmcdgafmukhijsctpspy","cxkhcgbrleqmcdgafmukhijsctpsct","cxkhcgbrleqmcdgafmukhijsctpsov","cxkhcgbrleqmcdgafmukhijsctpsqb","cxkhcgbrleqmcdgafmukhijsctpsos","cxkhcgbrleqmcdgafmukhijsctpsez","cxkhcgbrleqmcdgafmukhijsctpstg","cxkhcgbrleqmcdgafmukhijsctpsjj","cxkhcgbrleqmcdgafmukhijsctpsks","cxkhcgbrleqmcdgafmukhijsctpslo","cxkhcgbrleqmcdgafmukhijsctpsmt","cxkhcgbrleqmcdgafmukhijsctpsjs","cxkhcgbrleqmcdgafmukhijsctpssk","cxkhcgbrleqmcdgafmukhijsctpsxv","cxkhcgbrleqmcdgafmukhijsctpsst","cxkhcgbrleqmcdgafmukhijsctpsql","cxkhcgbrleqmcdgafmukhijsctpssf","cxkhcgbrleqmcdgafmukhijsctpsww","cxkhcgbrleqmcdgafmukhijsctpspf","cxkhcgbrleqmcdgafmukhijsctpste","cxkhcgbrleqmcdgafmukhijsctpsjm","cxkhcgbrleqmcdgafmukhijsctpsem","cxkhcgbrleqmcdgafmukhijsctpscx","cxkhcgbrleqmcdgafmukhijsctpsth","cxkhcgbrleqmcdgafmukhijsctpsjk","cxkhcgbrleqmcdgafmukhijsctpsxx","cxkhcgbrleqmcdgafmukhijsctpsdq","cxkhcgbrleqmcdgafmukhijsctpsze","cxkhcgbrleqmcdgafmukhijsctpsvt","cxkhcgbrleqmcdgafmukhijsctpsii","cxkhcgbrleqmcdgafmukhijsctpsda","cxkhcgbrleqmcdgafmukhijsctpsxd","cxkhcgbrleqmcdgafmukhijsctpszj","cxkhcgbrleqmcdgafmukhijsctpsin","cxkhcgbrleqmcdgafmukhijsctpslg","cxkhcgbrleqmcdgafmukhijsctpssn","cxkhcgbrleqmcdgafmukhijsctpszu","cxkhcgbrleqmcdgafmukhijsctpsck","cxkhcgbrleqmcdgafmukhijsctpskg","cxkhcgbrleqmcdgafmukhijsctpsod","cxkhcgbrleqmcdgafmukhijsctpsxm","cxkhcgbrleqmcdgafmukhijsctpsrh","cxkhcgbrleqmcdgafmukhijsctpsnq","cxkhcgbrleqmcdgafmukhijsctpsre","cxkhcgbrleqmcdgafmukhijsctpsph","cxkhcgbrleqmcdgafmukhijsctpskh","cxkhcgbrleqmcdgafmukhijsctpsbk","cxkhcgbrleqmcdgafmukhijsctpsqg","cxkhcgbrleqmcdgafmukhijsctpsbv","cxkhcgbrleqmcdg","cxkhcgbrleqmcdgafmukhijsctpstu","cxkhcgbrleqmcdgafmukhijsctpsoz","cxkhcgbrleqmcdgafmukhijsctpssj","cxkhcgbrleqmcdgafmukhijsctpshu","cxkhcgbrleqmcdgafmukhijsctpsyo","cxkhcgbrleqmcdgafmukhijsctpsrg","cxkhcgbrleqmcdgafmukhijsctpsta","cxkhcgbrleqmcdgafmukhijsctpswk","cxkhcgbrleqmcdgafmukhijsctpsht","cxkhcgbrleqmcdgafmukhijsctpslb","cxkhcgbrleqmcdgafmukhijsctpssv","cxkhcgbrleqmcdgafmukhijsctpsol","cxkhcgbrleqmcdgafmukhijsctpslv","cxkhcgbrleqmcdgafmukhijsctpshv","cxkhcgbrleqmcdgafmukhijsctpske","cxkhcgbrleqmcdgafmukhijsctpsdf","cxkhcgbrleqmcdgafmukhijsctpskj","cxkhcgbrleqmcdgafmukhijsctpsfx","cxkhcgbrleqmcdgafmukhijsctpskl","cxkhcgbrleqmcdgafmukhijsctpsof","cxkhcgbrleqmcdgafmukhijsctpsqj","cxkhcgbrleqmcdgafmukhijsctpsry","cxkhcgbrleqmcdgafmukhijsctpstt","cxkhcgbrleqmcdgafmukhijsctpsqm","cxkhcgbrleqmcdgafmukhijsctpssp","cxkhcgbrleqmcdgafmukhijsctpspv","cxkhcgbrleqmcdgafmukhijsctpsiz","cxkhcgbrleqmcdgafmukhijsctpsar","cxkhcgbrleqmcdgafmukhijsctpsln","cxkhcgbrleqmcdgafmukhijsctpsdo","cxkhcg","cxkhcgbrleqmcdgafmukhi","cxkhcgbrleqmcdgafmukhijsctpsdx","cxkhcgbrleqmcdgafmukhijsct","cxkhcgbrleqmcdgafmukhijsctpstc","cxkhcgbrleqmcdgafmukhijsctpsac","cxkhcgbrleqmcdgafmukhijsctpsea","cxkhcgbrleqmcdgafmukhijsctpsaa","cxkhcgbrleqmcdgafmukhijsctpsjr","cxkhcgbrleqmcdgafmukhijsctpsqq","cxkhcgbrleqmcdgafmukhijsctpsxj","cxkhcgbrleqmcdgafmukhijsctpsnm","cxkhcgbrleqmcdgafmukhijsctpsjz","cxkhcgbrleqmcdgafmukhijsctpsjx","cxkhcgbrleqmcdgafmukhijsctpsrk","cxkhcgbrleqmcdgafmukhijsctpsuu","cxkhcgbrle","cxkhcgbrleqmcdgafmukhijsctpsfv","cxkhcgbrleqmcdgafmukhijsctpshb","cxkhcgbrleqmcdgafmukhijsctpsrs","cxkhcgbrleqmcdgafmukhijsctpscl","cxkhcgbrleqmcdgafmukhijsctpsmi","cxkhcgbrleqmcdgafmukhijsctpslz","cxkhcgbrleqmcdgafmukhijsctpsfp","cxkhcgbrleqmcdgafmukhijsctpsyv","cxkhcgbrleqmcdgafmukhijsctpsad","cxkhcgbrleqmcdgafmukhijsctpspk","cxkhcgbrleqmcdgafmukhijsctpsxa","cxkhcgbrleqmcdgafmukhijsctpshs","cxkhcgbrleqmcdgafmukhijsctpszf","cxkhcgbrleqmcdgafmukhijsctpsnj","cxkhcgbrleqmcdgafmukhijsctpshn","cxkhcgbrleqmcdgafmukhijsctpsng","cxkhcgbrleqmcdgafmukhijsctpswx","cxkhcgbrleqmcdgafmukhijsctpsiv","cxkhcgbrleqmcdgafmukhijsctpsbg","cxkhcgbrleqmcdgafmukhijsctpslu","cxkhcgbrleqmcdgafmukhijsctpsnr","cxkhcgbrleqmcdgafmukhijsctpsje","cxkhcgbrleqmcdgafmukhijsctpsmz","cxkhcgbrleqmcdgafmukhijsctpsrn","cxkhcgbrleqmcdgafmukhijsctpsen","cxkhcgbrleqmcdgafmukhijsctpsvp","cxkhcgbrleqmcdgafmukhijsctpsoc","cxkhcgbrleqmcdgafmukhijsctpsbw","cxkhcgbrleqmcdgafmukhijsctpshy","cxkhcgbrleqmcdgafm","cxkhcgbrleqmcdgafmukhijsctpsqz","cxkhcgbrleqmcdgafmukhijsctpsxr","cxkhcgbrleqmcdgafmukhijsctpslt","cxkhcgbrleqmcdgafmukhijsctpsdy","cxkhcgbrleqmcdgafmukhijsctpsde","cxkhcgbrleqmcdgafmukhijsctpsig","cxkhcgbrleqmcdgafmukhijsctpsax","cxkhcgbrleqmcdgafmukhijsctpsqs","cxkhcgbrleqmcdgafmukhijsctpsoo","cxkhcgbrleqmcdgafmukhijsctpsba","cxkhcgbrleqmcdgafmukhijsctpsca","cxkhcgbrleqmcdgafmukhijsctpses","cxkhcgbrleqmcdgafmukhijsctpszo","cxkhcgbrleqmcdgafmukhijsctpsoy","cxkhcgbrleqmcdgafmukhijsctpskn","cxkhcgbrleqmcdgafmukhijsctpsfg" };
    // vector<string> words = { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    // vector<string> words = { "r","kt","jtgt","j","jtg","rdwy","chkext","c","l","zo","lnp","k","jt","chke","ktui","rd","jtgtha","ch","chkex" };
    // vector<string> words = {"b", "br", "bre", "brea", "break", "breakf", "breakfa", "breakfas", "breakfast", "l", "lu", "lun", "lunc", "lunch", "d", "di", "din", "dinn", "dinne", "dinner"};
    auto res = sol.longestWord(words);
    cout << res << endl;
    
    return 0;
}