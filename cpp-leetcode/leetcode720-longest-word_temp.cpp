#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 42 / 59 test cases passed. */
class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.empty()) return "";
        auto cmp0 = [](string s1, string s2)
        {
            return s1.size() < s2.size();
        };        
        sort(words.begin(), words.end(), cmp0);  
        
        vector<pair<string, int>> kvVect;
        for (auto word : words)
        {
            if (isAllSubstrExist(word, words) && isSubstrCountMeet(word, words))
                kvVect.push_back(make_pair(word, word.size()));
        }
        auto cmp = [](pair<string, int> p1, pair<string, int> p2)
        {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        };
        sort(kvVect.begin(), kvVect.end(), cmp);
        return kvVect.front().first;
    }

    bool isAllSubstrExist(string theWord, vector<string> words)
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
    // vector<string> words = { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    // vector<string> words = { "r","kt","jtgt","j","jtg","rdwy","chkext","c","l","zo","lnp","k","jt","chke","ktui","rd","jtgtha","ch","chkex" };
    vector<string> words = { "tgjrbffdokudfdunnbfyylfandlhzf","tgjrbffdokudfdunnbfyylfandlhsz","tgjrbffdokudfdunnbfyylfandlhcx","tgjrbffdokudfdunnbfyylfandlhdg","tgjrbffdokudfdunnbfyylfandlhwz","tgjrbffdokudfdunnbfyylfandlhtk","tgjrbffdokudfdunnbfyylfandlhdd","tgjrbffdokudfdunnbfyylfandlhtf","tgjrbffdokudfdunnbfyylfandlhbg","tgjrbffdokudfdunnbfyylfandlhju","tgjrbffdokudfdunnbfyylfandlhyx","tgjrbffdokudfdunnbfyylfandlhxd","tgjrbffdokudfdunnbfyylfandlhfr","tgjrbffdokudfdunnbfyylfandlhiy","tgjrbffdokudfdunnbfyylfandlhlu","tgjrbffdokudfdunnbfyylfandlhc","tgjrbffdokudfdunnbfyylfandlhxc","tgjrbffdokudfdunnbfyylfandlhvh","tgjrbffdokudfdunnbfyylfandlhhj","tgjrbffdokudfdunnbfyylfandlhoy","tgjrbffdokudfdunnbfyylfandlhp","tgjrbffdokudfdunnbfyylfandlhje","tgjrbffdokudfdunnbfyylfandlhhe","tgjrbffdokudfdunnbfyylfandlhcs","tgjrbffdokudfdunnbfyylfandlhib","tgjrbffdokudfdunnbfyylfandlhag","tgjrbffdokudfdunnbfyylfandlhmd","tgjrbffdokudfdunnbfyylfandlhez","tgjrbffdokudfdunnbfyylfandlhhu","tgjrbffdokudfdunnbfyylfandlhep","tgjrbffdokudfdunnbfyylfandlhuk","tgjrbffdokudfdunnbfyylfandlhuf","tgjrbffdokudfdunnbfyylfandlhrb","tgjrbffdokudfdunnbfyylfandlhdl","tgjrbffdokudfdunnbfyylfandlhhk","tgjrbffdokudfdunnbfyylfandlhht","tgjrbffdokudfdunnbfyylfandlhlw","tgjrbffdokudfdunnbfyylfandlhnc","tgjrbffdokudfdunnbfyylfandlhfw","tgjrbffdo","tgjrbffdokudfdunnbfyylfandlhqc","tgjrbffdokudfdunnbfyylfandlhpc","tgjrbffdokudfdunnbfyylfandlhqk","tgjrbffdokudfdunnbfyylfandlhcm","tgjrbffdokudfdunnbfyylfandlhgb","tgjrbffdokudfdunnbfyylfandlhsb","tgjrbffdokudfdunnbfyylfandlhpf","tgjrbffdokudfdunnbfyylfandlhaw","tgjrbffdokudfdunnbfyylfandlhyz","tgjrbffdokudfdunnbfyylfandlhra","tgjrbffdokudfdunnbfyylfandlhre","tgjrbffdokudfdunnbfyylfandlhij","tgjrbffdokudfdunnbfyylfandlhku","tgjrbffdokudfdunnbfyylfandlhyd","tgjrbffdokudfdunnbfyylfandlhpl","tgjrbffdokudfdunnbfyylfandlhto","tgjrbffdokudfdunnbfyylfandlhjz","tgjrbffdokudfdunnbfyylfandlhjg","tgjrbffdokudfdunnbfyylfandlhty","tgjrbffdokudfdunnbfyylfandlhcd","tgjrbffdokudfdunnbfyylfandlhjo","tgjrbffdokudfdunnbfyylfandlhrt","tgjrbffdokudfdunnbfyylfandlhfs","tgjrbffdokudfdunnbfyylfandlhbj","tgjrbffdokudfdunnbfyylfandlhyr","tgjrbffdokudfdunnbfyylfandlhwj","tgjrbffdokudfdunnbfyylfandlhlm","tgjrbffdokudfdunnbfyylfandlhwh","tgjrbffdokudfdunnbfyylfandlhtz","tgjrbffdokudfdunnbfyylfandlhca","tgjrbffdokudfdunnbfyylfandlhnk","tgjrbffdokudfdunnbfyylfandlhq","tgjrbffdokudfdunnbfyylfandlhsi","tgjrbffdokudfdunnbfyylfandlhky","tgjrbffdokudfdunnbfyylfandlhru","tgjrbffdokudfdunnbfyylfandlhjw","tgjrbffdokudfdunnbfyylfandlhfp","tgjrbffdokudfdunnbfyylfandlhlf","tgjrbffdokudfdunnbfyylfandlhkb","tgjrbffdokudfdunnbfyylfandlhmu","tgjrbffdokudfdunnbfyylfandlhfn","tgjrbffdokudfdunnbfyylfandlhxj","tgjrbffdokudfdunnbfyylfandlhsy","tgjrbffdokudfdunnbfyylfandlhse","tgjrbffdokudfdunnbfyylfandlhom","tgjrbffdokudfdunnbfyylfandlhoh","tgjrbffdokudfdunnbfyylfandlhny","tgjrbffdokudfdunnbfyylfandlhls","tgjrbffdokudfdunnbfyylfandlhgx","tgjrbffdokudfdunnbfyylfandlhee","tgjrbffdokudfdunnbfyylfandlhab","tgjrbffdokudfdunnbfyylfandlhzd","tgjrbffdokudfdunnb","tgjrbffdokudfdunnbfyylfandlhnm","tgjrbffdokudfdunnbfyylfandlhtc","tgjrbffdokudfdunnbfyylfandlhdm","tgjrbffdokudfdunnbfyylfandlhn","tgjrbffdokudfdunnbfyylfandlhwd","tgjrbffdokudfdunnbfyylfandlhsg","tgjrbffdokudfdunnbfyylfandlhau","tgjrbffdokudfdunnbfyylfandlhvj","tgjrbffdokudfdunnbfyylfandlhji","tgjrbffdokudfdunnbfyylfandlhrw","tgjrbffdokudfdunnbfyylfandlhcn","tgjrbffdokudfdunnbfyylfandlhqt","tgjrbffdokudfdunnbfyylfandlh","tgjrbffdokudfdunnbfyylfandlhjd","tgjrbffdokudfdunnbfyylfandlhkl","tgj","tgjrbffdokudfdunnbfyylfandlhci","tgjrbffdokudfdunnbfyylfandlhzp","tgjrbffdokudfdunnbfyylfandlhnp","tgjrbffdokudfdunnbfyylfandlhgi","tgjrbffdokudfdunnbfyylfandlhrz","tgjrbffdokudfdunnbfyylfandlhkc","tgjrbffdokudfdunnbfyylfandlhti","tgjrbffdokudfdunnbfyylfandlhye","tgjrbffdokudfdunnbfyylfandlhbr","tgjrbffdokudfdunnbfyylfandlhqq","tgjrbffdokudfdunnbfyylfandlhnv","tgjrbffdokudfdunnbfyylfandlhzb","tgjrbffdokudfdunnbfyylfandlhkm","tgjrbffdokudfdunnbfyylfandlhcc","tgjrbffdokudfdunnbfyylfandlhhl","tgjrbffdokudfdunnbfyylfandlheg","tgjrbffdokudfdunnbfyylfandlhxb","tgjrbffdokudfdunnbfyylfandlhmj","tgjrbffdokudfdunnbfyylfandlhwc","tgjrbffdokudfdunnbfyylfandlhfg","tgjrbffdokudfdunnbfyylfandlhgl","tgjrbffdokudfdunnbfyylfandlhex","tgjrbffdokudfdunnbfyylfandlhfk","tgjrbffdokudfdunnbfyylfandlhl","tgjrbffdokudfdunnbfyylfandlhgy","tgjrbffdokudfdunnbfyylfandlhft","tgjrbffdokudfdunnbfyylfandlhuu","tgjrbffdokudfdunnbfyylfandlhgm","tgjrbffdokudfdunnbfyylfandlhgv","tgjrbffdokudfdunnbfyylfandlhno","tgjrbffdokudfdunnbfyylfandlhis","tgjrbffdokudfdunnbfyylfandlhvb","tgjrbffdokudfdunnbfyylfandlhvm","tgjrbffdokudfdunnbfyylfandlhyv","tgjrbffdokudfdunnbfyylfa","tgjrbffdokudfdunnbfyylfandlhko","tgjrbffdokudfdunnbfyylfandlhhp","tgjrbffdokudfdunnbfyylfandlhjl","tgjrbffdokudfdunnbfyylfandlhel","tgjrbffdokudfdunnbfyylfandlhml","tgjrbffdokudfdunnbfyylfandlhjn","tgjrbffdokudfdunnbfyylfandlhbl","tgjrbffdokudfdunnbfyylfandlhac","tgjrbffdokudfdunnbfyylfandlhyg","tgjrbffdokudfdunnbfyylfandlhzx","tgjrbffdokudfdunnbfyylfandlhoc","tgjrbffdokudfdunnbfyylfandlhmi","tgjr","tgjrbffdokudfdunnbfyylfandlhhz","tgjrbffdokudfdunnbfyylfandlhrq","tgjrbffdokudfdunnbfyylfandlhhn","tgjrbffdokudfdunnbfyylfandlhi","tgjrbffdokudfdunnbfyylfandlhmc","tgjrbffdokudfdunnbfyylfandlhgc","tgjrbffdokudfdunnbfyylfandlhfo","tgjrbffdokudfdunnbfyylfandlhhc","tgjrbffdokudfdunnbfyylfandlhyy","tgjrbffdokudfdunnbfyylfandlhat","tgjrbffdokudfdunnbfyylfandlhly","tgjrbffdokudfdunnbfyylfandlhrv","tgjrbffdokudfdunnbfyylfandlhj","tgjrbffdokudfdunnbfyylfandlhgp","tgjrbffdokudfdunnbfyylfandlhwl","tgjrbffdokudfdunnbfyylfandlhuh","tgjrbffdokudfdunnbfyylfandlhbf","tgjrbffdokudfdunnbfyylfandlhcg","tgjrbffdokudfdunnbfyylfandlhys","tgjrbffdokudfdunnbfyylfandlhck","tgjrbffdokudfdunnbfyylfandlhyw","tgjrbffdokudfdunnbfyylfandlhwt","tgjrbffdokudfdunnbfyylfandlhds","tgjrbffdokudfdunnbfyylfandlhur","tgjrbffdokudfdunnbfyylfandlhbe","tgjrbffdokudfdunnbfyylfandlhxh","tgjrbffdokudfdunnbfyylfandlhpq","tgjrbffdokudfdunnbfyylfandlhio","tgjrbffdokudfdunnbfyylfandlhm","tgjrbffdokudfdunnbfyylfandlhh","tgjrbffdokudfdunnbfyylfandlhmt","tgjrbffdokudfdunnbfyylfandlhpp","tgjrbffdokudfdunnbfyylfandlhdq","tgjrbffdokudfdu","tgjrbffdokudfdunnbfyylfandlhor","tgjrbffdokudfdunnbfyylfandlhvc","tgjrbffdokudfdunnbfyylfandlhfz","tgjrbffdokudfdunnbfyylfandlhpz","tgjrbffdokudfdunnbfyylfandlhwy","tgjrbffdokudfdunnbfyylfandlhla","tgjrbffdokudfdunnbfyylfandlhzm","tgjrbffdokudfdunnbfyylfandlhiq","tgjrbffdokudfdunnbfyylfandlhoz","tgjrbffdokudfdunnbfyylfandlhjr","tgjrbffdokudfdunnbfyylfandlhxr","tgjrbffdokudfdunnbfyylfandlhec","tgjrbffdokudfdunnbfyylfandlhmv","tgjrbffdokudfdunnbfyylfandlhfy","tgjrbffdokudfdunnbfyylfandlham","tgjrbffdokudfdunnbfyylfandlhuj","tgjrbffdokudfdunnbfyylfandlhsh","tgjrbffdokudfdunnbfyylfandlhbz","tgjrbffdokudfdunnbfyylfandlhmo","tgjrbffdokudfdunnbfyylfandlhyn","tgjrbffdokudfdunnbfyylfandlhrl","tgjrbffdokudfdunnbfyylfandlhus","tgjrbffdokudfdunnbfyylfandlhgr","tgjrbffdokudfdunnbfyylfandlhcr","tgjrbffdokudfdunnbfyylfandlhhb","tgjrbffdokudfdunnbfyylfandlhzq","tgjrbffdokudfdunnbfyylfandlhfv","tgjrbffdokudfdunnbfyylfandlhjf","tgjrbffdokudfdunnbfyylfandlhk","tgjrbffdokudfdunnbfyylfandlhlo","tgjrbffdokudfdunnbfyylfandlhww","tgjrbffdokudfdunnbfyylfandlhdr","tgjrbffdokudfdunnbfyylfandlhyj","tgjrbffdokudfdunnbfyylfandlhia","tgjrbffdokudfdunnbfyylfandlhkv","tgjrbffdokudfdunnbfyylfandlhwu","tgjrbffdokudfdunnbfyylfandlhnx","tgjrbffdokudfdunnbfyylfandlhuc","tgjrbffdokudfdunnbfyylfandlhqx","tgjrbffdokudfdunnbfyylfandlhfq","tgjrbffdokudfdunnbfyylfandlhzk","tgjrbffdokudfdunnbfyylfandlhpk","tgjrbffdokudfdunnbfyylfandlhta","tgjrbffdokudfdunnbfyylfandlhle","tgjrbffdokudfdunnbfyylfandlhkp","tgjrbffdokudfdunnbfyylfandlhou","tgjrbffdokudfdun","tgjrbffdokudfdunnbfyylfandlhcz","tgjrbffdokudfdunnbfyylfandlhev","tgjrbffdokudfdunnbfyylfandlhyu","tgjrbffdokudfdunnbfyylfandlhdc","tgjrbffdokudfdunnbfyylfandlhga","tgjrbffdokudfdunnbfyylfandlhnf","tgjrbffdokudfdunnbfyylfandlhlc","tgjrbffdokudfdunnbfyylfandlhyp","tgjrbffdokudfdunnbfyylfandlhtx","tgjrbffdokudfdunnbfyylfandlhmg","tgjrbffdokudfdunnbfyylfandlhnq","tgjrbffdokudfdunnbfyylfandlhqg","tgjrbffdokudfdunnbfyylfandlhms","tgjrbffdokudfdunnbfyylfandlhxf","tgjrbffdokudfdunnbfyylfandlhkr","tgjrbffdokudfdunnbfyylfandlhri","tgjrbffdokudfdunnbfyylfandlhix","tgjrbffdokudfdunnbfyylfandlhkw","tgjrbffdokudfdunnbfyylfandlhpr","tgjrbffdokudfdunnbfyylfandlhsj","tgjrbffdokudfdunnbfyylfandlhic","tgjrbffdokudfdunnbfyylfandlhry","tgjrbffdokudfdunnbfyylfandlhhq","tgjrbffdokudfdunnbfyylfandlhog","tgjrbffdokudfdunnbfyylfandlhqz","tgjrbffdokudfdunnbfyylfandlhux","tgjrbffdokudfdunnbfyylfandlhlb","tgjrbffdokudfdunnbfyylfandlhlj","tgjrbffdokudfdunnbfyylfandlhaq","tgjrbffdokudfdunnbfyylfandlhbw","tgjrbffdokudfdunnbfyylfandlhkk","tgjrbffdokudfdunnbfyylfandlhub","tgjrbffdokudfdunnbfyylfandlhqh","tgjrbffdokudfdunnbfyylfandlhiv","tgjrbffdokudfdunnbfyylfandlhge","tgjrbffdokudfdunnbfyylfandlhek","tgjrbffdokudfdunnbfyylfandlhwq","tgjrbffdokudfdunnbfyylfandlhvr","tgjrbffdokudfdunnbfyylfandlhzi","tgjrbffdokudfdunnbfyylfandlhgu","tgjrbffdokudfdunnbfyylfandlhud","tgjrbffdokudfdunnbfyylfandlhsa","tgjrbffdokudfdunnbfyylfandlhmp","tgjrbffdokudfdunnbfyylfandlhrj","tgjrbffdokudfdunnbfyylfandlhed","tgjrbffdokudfdunnbfyylfandlhen","tgjrbffdokudfdunnbfyylfandlhxz","tgjrbffdokudfdunnbfyylfandlhvq","tgjrbffdokudfdunnbfyylfandlhqf","tgjrbffdokudfdunnbfyylfandlhgd","tgjrbffdokudfdunnbfyylfandlhew","tgjrbffdokudfdunnbfyylfandlhnj","tgjrbf","tgjrbffdokudfdunnbfyylfandlhul","tgjrbffdokudfdunnbfyylfandlhjt","tgjrbffdokudfdunnbfyylfandlhiu","tgjrbffdokudfdunnbfyylfandlhgg","tgjrbffdokudfdunnbfyylfandlhnu","tgjrb","tgjrbffdokudfdunnbfyylfandlhqe","tgjrbffdokudfdunnbfyylfandlhd","tgjrbffdokudfdunnbfyylfandlhsq","tgjrbffdokudfdunnbfyylfandlhy","tgjrbffdokudfdunnbfyylfandlhdx","tgjrbffdokudfdunnbfyylfandlhan","tgjrbffdokudfdunnbfyylfandlhcl","tgjrbffdokudfdunnbfyylfandlhon","tgjrbffdokudfdunnbfyylfandlhjv","tgjrbffdokudfdunnbfyylfandlhni","tgjrbffdokudfdunnbfyylfandlhwb","tgjrbffdokudfdunnbfyylfandlhxe","tgjrbffdokudfdunnbfyylfandlhrm","tgjrbffdokudfdunnbfyylfandlhax","tgjrbffdokudfdunnbfyylfandlhdp","tgjrbffdokudfdunnbfyylfandlhot","tgjrbffdokudfdunnbfyylfandlhwa","tgjrbffdokudfdunnbfyylfandlhfl","tgjrbffdokudfdunnbfyylfandlhho","tgjrbffdokudfdunnbfyylfandlhrs","tgjrbffdokudfdunnbfyylfandlhaj","tgjrbffdokudfdunnbfyylfandlhzh","tgjrbffdokudfdunnbfyylfandlhdw","tgjrbffdokudfdunnbfyylfandlhsu","tgjrbffdokudfdunnbfyylfandlhxy","tgjrbffdokudfdunnbfyylfandlhpj","tgjrbffdokudfdunnbfyylfandlhav","tgjrbffdokudfdunnbfyylfandlhjk","tgjrbffdokudfdunnbfyylfandlhcp","tgjrbffdokudfdunnbfyylfandlhhd","tgjrbffdokudfdunnbfyylfandlhkh","tgjrbffdokudfdunnbfyylfandlhgf","tgjrbffdokudfdunnbfyylfandlhhy","tgjrbffdokudfdunnbfyylfandlhha","tgjrbffdokudfdunnbfyylfandlhsd","tgjrbffdokudfdunnbfyylfandlhnn","tgjrbffdokudfdunnbfyylfandlhyl","tgjrbffdokudfdunnbfyylfandlhvs","tgjrbffdokudfdunnbfyylfandlhhf","tgjrbffdokudfdunnbfyylfandlhwe","tgjrbffdokudfdunnbfyylfandlhef","tgjrbffdokudfdunnbfyylfandlha","tgjrbffdokudfdunnbfyylfandlhjx","tgjrbffdokudfdunnbfyylfandlhsw","tgjrbffdokudfdunnbfyylfandlht","tgjrbffdokudfdunnbfyylfandlhvy","tgjrbffdokudfdunnbfyylfandlho","tgjrbffdokudfdunnbfyylfandlhss","tgjrbffdokudfdunnbfyylfandlhgh","tgjrbffdokudfdunnbfyylfandlhod","tgjrbffdokudfdunnbfyylfandlhpu","tgjrbffdokudfdunnbfyylfandlhie","tgjrbffdokudfdunnbfyylfandlhpb","tgjrbffdokudfdunnbfyylfandlhcu","tgjrbffdokudfdunnbfyylfandlhpv","tgjrbffdokudfdunnbfyylfandlhxp","tgjrbffdokudfdunnbfyylfandlhtu","tgjrbffdokudfdunnbfyylfandlhmm","tgjrbffdokudfdunnbfyylfandlhqu","tgjrbffdokudfdunnbfyylfandlhif","tgjrbffdokudfdunnbfyylfandlhtm","tgjrbffdokudfdunnbfyylfandlhsp","tgjrbffdokudfdunnbfyylfandlhpm","tgjrbffdokudfdunnbfyylfandlhfx","tgjrbffdokudfdunnbfyylfandlhtb","tgjrbffdokudfdunnbfyylfandlhdv","tgjrbffdokudfdunnbfyylfandlhma","tgjrbffdokudfdunnbfyylfandlhdb","tgjrbffdokudfdunnbfyylfandlhpe","tgjrbffdokudfdunnbfyylfandlhql","tgjrbffdokudfdunnbfyylfandlhao","tgjrbffdokudfdunnbfyylfandlhjh","tgjrbffdokudfdunnbfyylfandlhiw","tgjrbffdokudfdunnbfyylfandlhid","tgjrbffdokudfdunnbfyylfandlhxo","tgjrbffdokudfdunnbfyylfandlhzs","tgjrbffdokudfdunnbfyylfandlhqs","tgjrbffdokudfdunnbfyylfandlhvn","tgjrbffdokudfdunnbfyylfandlhna","tgjrbffdokudfdunnbfyylfandlhtg","tgjrbffdokudfdunnbfyylfandlhqn","tgjrbffdokudfdunnbfyylfandlhpt","tgjrbffdokudfdunnbfyylfandlheu","tgjrbffdokudfdunnbfyylfandlhdt","tgjrbffdokudfdunnbfyylfandlhbh","tgjrbffdokudfdunnbfyylfandlhvd","tgjrbffdokudfdunnbfyylfandlhym","tgjrbffdokudfdunnbfyylfandlhnb","tgjrbffdokudfdunnbfyylfandlhpn","tgjrbffdokudfdunnbfyylfandlhlv","tgjrbffdokudfdunnbfyylfandlhai","tgjrbffdokudfdunnbfyylfandlhzc","tgjrbffdokudfdunnbfyylfandlhvo","tgjrbffdokudfdunnbfyylfandlhob","tgjrbffdokudfdunnbfyylfandlhit","tgjrbffdokudfdunnbfyylfandlhtp","t","tgjrbffdokudfdunnbfyylfandlhst","tgjrbffdokudfdunnbfyylfandlhpg","tgjrbffdokudfdunnbfyylfandlhsf","tgjrbffdokudfdunnbfyylfandlhmz","tgjrbffdokudfdunnbfyylfandlhvk","tgjrbffdokudfdunnbfyylfandlhlq","tgjrbffdokudfdunnbfyylfandlhja","tgjrbffdokudfdunnbfyylfandlhdk","tgjrbffdokudfdunnbfyylfandlhvg","tgjrbffdokudfdunnbfyylfandlhah","tgjrbffdokudfdunnbfyylfandlhmk","tgjrbffdokudfdunnbfyylfandlhxm","tgjrbffdokudfdunnbfyylfandlhwk","tgjrbffdokudfdunnbfyyl","tgjrbffdokudfdunnbfyylfandlhpd","tgjrbffdokudfdunnbfyylfandlhxg","tgjrbffdokudfdunnbfyylfandlhwf","tgjrbffdokudfdunnbfyylfandlhnl","tgjrbffdokudfdunnbfyylfandlhxn","tgjrbffdokudfdunnbfyylfandlhkj","tgjrbffdokudfdunnbfyylfandlhjp","tgjrbffdokudfdunnbfyylfandlhae","tgjrbffdokudfdunnbfyylfandlhjm","tgjrbffdokudfdunnbfyylfandlhey","tgjrbffdokudfdunnbfyylfandlhpy","tgjrbffdokudfdunnbfyylfandlhtj","tgjrbffdokudfdunnbfyylfandlhmn","tgjrbffdokudfdunnbfyylfandlhyo","tgjrbffdokudfdunnbfyylfandlhdn","tgjrbffdokudfdunnbfyylfandlhjb","tgjrbffdokudfdunnbfyylfandlhco","tgjrbffdokudfdunnbf","tgjrbffdokudfdunnbfyylfandlhxq","tgjrbffdokudfdunnbfyylfandlhap","tgjrbffdokudfdunnbfyylfandlhzz","tgjrbffdokudfdunnbfyylfandlhzy","tgjrbffdokudfdunnbfyylfandlhso","tgjrbffdokudfdunnbfyylfandlhrk","tgjrbffdokudfdunnbfyylfandlhnr","tgjrbffdokudfdunnbfyylfandlhph","tgjrbffdokudfdunnbfyylfandlhng","tgjrbffdokudfdunnbfyylfandlhx","tgjrbffdokudfdunnbfyylfandlhvx","tgjrbffdokudfdunnbfyylfandlhth","tgjrbffdokudfdunnbfyylfandlhqr","tgjrbffdokudfdunnbfyylfandlhz","tgjrbffdokudfdunnbfyylfandlhe","tgjrbffdokudfdunnbfyylfandlhiz","tgjrbffdokudfdunnbfyylfandlhbp","tgjrbffdokudfdunnbfyylfandlhop","tgjrbffdokudfdunnbfyylfandlhow","tgjrbffdokudfdunnbfyylfandlhwx","tgjrbffdokudfdunnbfyylfandlhlr","tgjrbffdokudfdunnbfyylfandlhb","tgjrbffdokudfdunnbfyylfandlhya","tgjrbffdokudfdunnbfyylfandlhzv","tgjrbffdokudfdunnbfyylfandlhcj","tgjrbffdokudfdunnbfyylfandlhkx","tgjrbffdokudfdunnbfyylfandlhet","tgjrbffdokudfdunnbfyylfandlhhs","tgjrbffdokudfdunnbfyylfandlhkg","tgjrbffdokudfdunnbfyylfandlhu","tgjrbffdokudfdunnbfyylfandlhsr","tgjrbffdokudfdunnbfyylfandlhsm","tgjrbffdokudfdunnbfyylfandlhyb","tgjrbffdokudfdunnbfyylfandlhcw","tgjrbffdokudfdunnbfyylfandlhrf","tgjrbffdokudfdunnbfyylfandlhxi","tgjrbffdokudfdunnbfyylfandlhui","tgjrbffdokudfdunnbfyylfandlhgo","tgjrbffdokudfdunnbfyylfandlhbu","tgjrbffdokudfdunnbfyylfandlhbq","tgjrbffdokudfdunnbfyylfandlhfj","tgjrbffdokudfdunnbfyylfandlhmx","tgjrbffdokudfdunnbfyylfandlhda","tgjrbffdokudfdunnbfyylfandlhvi","tgjrbffdokudfdunnbfyylfandlhrr","tgjrbffdokudfdunnbfyylfandlhoj","tgjrbffdokudfdunnbfyylfandlhir","tgjrbffdokudfdunnbfyylfandlhct","tgjrbffdokudfdunnbfyylfandlhnh","tgjrbffdokudfdunnbfyylfandlhpo","tgjrbffdokudfdunnbfyylfandlhsv","tgjrbffdokudfd","tg","tgjrbffdokudf","tgjrbffdokudfdunnbfyylfandlhfe","tgjrbffdokudfdunnbfyylfandlhg","tgjrbffdokudfdunnbfyylfandlhte","tgjrbffdokudfdunnbfyylfandlher","tgjrbffdokudfdunnbfyylfandlhyf","tgjrbffdokudfdunnbfyylfandlhpi","tgjrbffdokudfdunnbfyylfandlhbb","tgjrbffdokudfdunnbfyylfandlhii","tgjrbffdokudfdunnbfyylfandlhff","tgjrbffdokudfdunnbfyylfandlhbk","tgjrbffdokudfdunnbfyylfandlhtq","tgjrbffdokudfdunnbfyylfandlhuq","tgjrbffdokudfdunnbfyylfandlhbi","tgjrbffdokudfdunnbfyylfandlheh","tgjrbffdokudfdunnbfyylfandlhhi","tgjrbffdokudfdunnbfyylfandlhdh","tgjrbffdokudfdunnbfyylfandlhes","tgjrbffdokudfdunnbfyylfandlhwg","tgjrbffdokudfdunnbfyylfandlhuv","tgjrbffdokudfdunnbfyylfandlhzj","tgjrbffdokudfdunnbfyylfandlhgz","tgjrbffdokudfdunnbfyylfandlhei","tgjrbffdokudfdunnbfyylfandlhok","tgjrbffdokudfdunnbfyylfandlhip","tgjrbffdokudfdunnbfyylfandlhrd","tgjrbffdokudfdunnbfyylfandlhyk","tgjrbffdokudfdunnbfyylfandlhhg","tgjrbffdokudfdunnbfyylfandlhkz","tgjrbffdokudfdunnbfyylfandlhrh","tgjrbffdokudfdunnbfyylfandlhgq","tgjrbffdokudfdunnbfyylfandlhnz","tgjrbffdokudfdunnbfyylfandlhrx","tgjrbffdokudfdunnbfyylfandlhwo","tgjrbffdokudfdunnbfyylfandlhhx","tgjrbffdokudfdunnbfyylfandlhva","tgjrbffdokudfdunnbfyylfandlhut","tgjrbffdokudfdunnbfyylfandlhde","tgjrbffdokudfdunnbfyylfandlhuz","tgjrbffdokudfdunnbfyylfandlhby","tgjrbffdokudfdunnbfyylfandlhcb","tgjrbffdoku","tgjrbffdokudfdunnbfyylfandlhce","tgjrbffdokudfdunnbfyylfandlhej","tgjrbffdokudfdunnbfyylfandlhcf","tgjrbffdokudfdunnbfyylfandlhks","tgjrbffdokudfdunnbfyylfandlhnd","tgjrbffdokudfdunnbfyylfandlhr","tgjrbffdokudfdunnbfyylfandlhsk","tgjrbffdokud","tgjrbffdokudfdunnbfyylfandlhpa","tgjrbffdokudfdunnbfyylfandlhqa","tgjrbffdokudfdunnbfyylfandlhmq","tgjrbffdokudfdunnbfyylfandlhcv","tgjrbffdokudfdunnbfyylfandlhof","tgjrbffdokudfdunnbfyylfandlhzg","tgjrbffdokudfdunnbfyylfandlhol","tgjrbffdokudfdunnbfyylfandlhoa","tgjrbffdokudfdunnbfyylfandlhik","tgjrbffdokudfdunnbfyylfandlhxw","tgjrbffdokudfdunnbfyylfandlhln","tgjrbffdokudfdunnbfyylfandlhbn","tgjrbffdokudfdunnbfyylfandlhzl","tgjrbffdokudfdunnbfyylfandlhme","tgjrbffdokudfdunnbfy","tgjrbffdokudfdunnbfyylfandlhbv","tgjrbffdokudfdunnbfyylfandlhqp","tgjrbffdokudfdunn","tgjrbffdokudfdunnbfyylfandlhvw","tgjrbffdokudfdunnbfyylfandlhas","tgjrbffdokudfdunnbfyylfandlhwn","tgjrbffdokudfdunnbfyylfandlhaf","tgjrbffdokudfdunnbfyylfandlhxs","tgjrbffdokudfdunnbfyylfan","tgjrbffdokudfdunnbfyylfandlhvf","tgjrbffdokudfdunnbfyylfandlhgk","tgjrbffdokudfdunnbfyylfandlhov","tgjrbffdokudfdunnbfyylfandlhmf","tgjrbffdokudfdunnbfyylfandlhld","tgjrbffdokudfdunnbfyylfandlhyh","tgjrbffdokudfdunnbfyylfandlhhr","tgjrbffdokudfdunnbfyylfandlhun","tgjrbffdokudfdunnbfyylfandlhmw","tgjrbffdokudfdunnbfyylfandlhil","tgjrbffdokudfdunnbfyylfandlhrg","tgjrbffdokudfdunnbfyylfandlhch","tgjrbffdokudfdunnbfyylfandlhqy","tgjrbffdokudfdunnbfyylfandlhfi","tgjrbffdokudfdunnbfyylfandlhhh","tgjrbffdokudfdunnbfyylfandlhug","tgjrbffdokudfdunnbfyylfandlhtn","tgjrbffdokudfdunnbfyylfandlhlp","tgjrbffdokudfdunnbfyylfandlhjj","tgjrbffdokudfdunnbfyylfandlhvz","tgjrbffdokudfdunnbfyylfandlhmh","tgjrbffdokudfdunnbfyylfandlhal","tgjrbffdokudfdunnbfyylfandlhvt","tgjrbffdokudfdunnbfyylfandlhdu","tgjrbffdokudfdunnbfyylfandlhbt","tgjrbffdokudfdunnbfyylfandlhuo","tgjrbffdokudfdunnbfyylfandlheq","tgjrbffdokudfdunnbfyylfandlhos","tgjrbffdokudfdunnbfyylfandlhxl","tgjrbffdokudfdunnbfyylfandlhw","tgjrbffdokudfdunnbfyylfandlhem","tgjrbffdokudfdunnbfyylfandlhmb","tgjrbffdokudfdunnbfyylfandlhbs","tgjrbffdokudfdunnbfyylfandlhgj","tgjrbffdokudfdunnbfyylfandlhih","tgjrbffdokudfdunnbfyylfandlhgs","tgjrbffdokudfdunnbfyylfandlhig","tgjrbffdokudfdunnbfyylfandlhbo","tgjrbffdokudfdunnbfyylfandlhua","tgjrbffdokudfdunnbfyylfandlhqd","tgjrbffdokudfdunnbfyylfandlhns","tgjrbffdokudfdunnbfyylfandlhtv","tgjrbffdokudfdunnbfyylfandlhdj","tgjrbffdokudfdunnbfyylfandlhgw","tgjrbffdokudfdunnbfyylfandlhfa","tgjrbffdokudfdunnbfyylfandlhgn","tgjrbffdokudfdunnbfyylfandl","tgjrbffdokudfdunnbfyylfandlhpx","tgjrbffdokudfdunnbfyylfandlhxk","tgjrbffdokudfdunnbfyylfandlhwr","tgjrbffdokudfdunnbfyylfandlhwm","tgjrbffdokudfdunnbfyylfandlhsl","tgjrbffdokudfdunnbfyylfandlhtw","tgjrbffdokudfdunnbfyylfandlhfh","tgjrbffdokudfdunnbfyylfandlhlg","tgjrbffdokudfdunnbfyylfandlhtt","tgjrbffdokudfdunnbfyylfandlhvv","tgjrbffdokudfdunnbfyylfandlhza","tgjrbffdokudfdunnbfyylfandlhjs","tgjrbffdokudfdunnbfyylfandlhwp","tgjrbffdokudfdunnbfyylfandlhps","tgjrbffdokudfdunnbfyylfandlhqb","tgjrbffdokudfdunnbfyylfandlhki","tgjrbffdokudfdunnbfyylfandlhdz","tgjrbffdokudfdunnbfyylfandlhxv","tgjrbffdokudfdunnbfyylfandlhox","tgjrbffdokudfdunnbfyylfandlhjq","tgjrbffdokudfdunnbfyylfandlhxt","tgjrbffdokudfdunnbfyylfandlhuy","tgjrbffdokudfdunnbfyylfandlhzw","tgjrbffdokudfdunnbfyylfandlhbd","tgjrbffdokudfdunnbfyylfandlhlt","tgjrbffdokudfdunnbfyylfandlhze","tgjrbffdokudfdunnbfyylfandlhum","tgjrbffdokudfdunnbfyylfandlhqv","tgjrbffdokudfdunnbfyylfandlhak","tgjrbffdokudfdunnbfyylfandlhvl","tgjrbffdokudfdunnbfyylfandlhhw","tgjrbffdokudfdunnbfyylfandlhbx","tgjrbffdokudfdunnbfyylfand","tgjrbffdokudfdunnbfyylfandlhfd","tgjrbffdokudfdunnbfyylfandlhim","tgjrbffdokudfdunnbfyylfandlhvp","tgjrbffdokudfdunnbfyylfandlhlh","tgjrbffdokudfdunnbfyylfandlhfc","tgjrbffdokudfdunnbfyylfandlhdo","tgjrbffdokudfdunnbfyylfandlhzo","tgjrbffdokudfdunnbfyylfandlhqo","tgjrbffdokudfdunnbfyylfandlhad","tgjrbffdokudfdunnbfyylfandlhwi","tgjrbffdokudfdunnbfyylfandlhzr","tgjrbffdokudfdunnbfyylfandlhsx","tgjrbffdokudfdunnbfyylfandlhf","tgjrbffdokudfdunnbfyylfandlhhm","tgjrbff","tgjrbffdokudfdunnbfyylfandlhkd","tgjrbffdokudfdunnbfyylfandlhuw","tgjrbffdokudfdunnbfyylfandlhwv","tgjrbffdokudfdunnbfyylfandlhlk","tgjrbffdokudfdunnbfyylfandlhnt","tgjrbffdokudfdunnbfyylfandlhlx","tgjrbffdokudfdunnbfyylfandlhvu","tgjrbffdokudfdunnbfyylfandlhke","tgjrbffdokudfdunnbfyylfandlhsc","tgjrbffdokudfdunnbfyylfandlhkf","tgjrbffdokudfdunnbfyylfandlhdy","tgjrbffdokudfdunnbfyylfandlhsn","tgjrbffdokudfdunnbfyylfandlhne","tgjrbffdokudfdunnbfyylfandlhdi","tgjrbffdokudfdunnbfyylfandlhli","tgjrbffdokudfdunnbfyylfandlhqm","tgjrbffdokudfdunnbfyylfandlhoq","tgjrbffdokudfdunnbfyylfandlhcy","tgjrbffdokudfdunnbfyylfandlhxa","tgjrbffdokudfdunnbfyylfandlhkq","tgjrbffdokudfdunnbfyylfandlhws","tgjrbffdokudfdunnbfyylfandlhhv","tgjrbffdokudfdunnbfyylfandlhjc","tgjrbffdokudfdunnbfyylfandlhfb","tgjrbffdokudfdunnbfyylfandlhv","tgjrbffd","tgjrbffdokudfdunnbfyylfandlhgt","tgjrbffdokudfdunnbfyylfandlhqj","tgjrbffdokudfdunnbfyylfandlhyt","tgjrbffdokudfdunnbfyylfandlhro","tgjrbffdokudfdunnbfyylfandlhyq","tgjrbffdokudfdunnbfyylfandlhbc","tgjrbffdokudfdunnbfyylfandlhbm","tgjrbffdokudfdunnbfyylfandlhba","tgjrbffdokudfdunnbfyylfandlhqi","tgjrbffdokudfdunnbfyylfandlhup","tgjrbffdokudfdunnbfyylfandlhyc","tgjrbffdokudfdunnbfyylfandlhkt","tgjrbffdokudfdunnbfyy","tgjrbffdokudfdunnbfyylfandlhtr","tgjrbffdokudfdunnbfyylfandlhpw","tgjrbffdokudfdunnbfyylfandlhcq","tgjrbffdokudfdunnbfyylfandlhzt","tgjrbffdokudfdunnbfyylf","tgjrbffdokudfdunnbfyylfandlhnw","tgjrbffdokudfdunnbfyylfandlhxu","tgjrbffdokudfdunnbfyylfandlhar","tgjrbffdokudfdunnbfyylfandlhfm","tgjrbffdokudfdunnbfyylfandlhmy","tgjrbffdokudfdunnbfyylfandlhoi","tgjrbffdokudfdunnbfyylfandlhay","tgjrbffdokudfdunnbfyylfandlheb","tgjrbffdokudfdunnbfyylfandlhaz","tgjrbffdokudfdunnbfyylfandlhrc","tgjrbffdokudfdunnbfyylfandlhka","tgjrbffdokudfdunnbfyylfandlhtl","tgjrbffdokudfdunnbfyylfandlhrn","tgjrbffdokudfdunnbfyylfandlhve","tgjrbffdokudfdunnbfyylfandlhts","tgjrbffdokudfdunnbfyylfandlhrp","tgjrbffdokudfdunnbfyylfandlhoe","tgjrbffdokudfdunnbfyylfandlhzn","tgjrbffdokudfdunnbfyylfandlhtd","tgjrbffdokudfdunnbfyylfandlhkn","tgjrbffdokudfdunnbfyylfandlheo","tgjrbffdokudfdunnbfyylfandlhzu","tgjrbffdokudfdunnbfyylfandlhea","tgjrbffdokudfdunnbfyylfandlhs","tgjrbffdokudfdunnbfyylfandlhyi","tgjrbffdokudfdunnbfyylfandlhfu","tgjrbffdokudfdunnbfyylfandlhlz","tgjrbffdokudfdunnbfyylfandlhmr","tgjrbffdokudfdunnbfyylfandlhxx","tgjrbffdokudfdunnbfyylfandlhue","tgjrbffdokudfdunnbfyylfandlhoo","tgjrbffdokudfdunnbfyylfandlhin","tgjrbffdok","tgjrbffdokudfdunnbfyylfandlhqw","tgjrbffdokudfdunnbfyylfandlhdf","tgjrbffdokudfdunnbfyylfandlhjy","tgjrbffdokudfdunnbfyylfandlhll","tgjrbffdokudfdunnbfyylfandlhaa" };
    auto res = sol.longestWord(words);
    cout << res << endl;
    
    return 0;
}