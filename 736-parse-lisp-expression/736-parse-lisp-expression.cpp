class Solution {
public:
    
    stringstream ss;
    unordered_map<string, vector<int>> var;
    int UNUSED = 1337;

    int evaluate(string s0) {
        string s;
        for(char c : s0) s.append(c == '(' ? " ( " : c == ')' ? " ) " : string(1, c)); 
        ss = stringstream(s);
        return solve().second;
    }

    pair<string, int> solve(){
        string t; ss >> t;
        int ret;
        if(t == "("){
            string op; ss >> op;
            if(op == "add" || op == "mult"){
                auto op1 = solve(), op2 = solve();
                string discard; ss >> discard;
                ret = op == "add" ? op1.second+op2.second : op1.second*op2.second;
            } else {
                vector<string> assign;
                pair<string, int> l, r;
                while(true){
                    l = solve(), r = solve(), ret = l.second;
                    if(r.first == ")") break;
                    var[l.first].push_back(r.second);
                    assign.push_back(l.first);
                }
                for(string a : assign) var[a].pop_back();
            }
        }
        else if(t == ")") ret = UNUSED;
        else if(isalpha(t.front())) ret = var[t].empty() ? UNUSED : var[t].back();
        else ret = stoi(t);
        return {t, ret};
    }   
};