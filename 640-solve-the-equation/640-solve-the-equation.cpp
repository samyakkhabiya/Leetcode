class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size(), sign = 1, coeff = 0, tot = 0, i = 0;
        for (int j = 0; j < n; j++) {
            if (equation[j] == '+' || equation[j] == '-') {
                if (j > i) tot += sign*stoi(equation.substr(i, j-i));
                i = j;
            }
            // corner case: x, -x, +x
            else if (equation[j] == 'x') {
                if ((i == j) || equation[j-1] == '+')
                    coeff += sign;
                else if (equation[j-1] == '-')
                    coeff -= sign;
                else 
                    coeff += sign*stoi(equation.substr(i, j-i));
                i = j+1;
            }
           // flip sign
            else if (equation[j] == '=') {
                if (j > i) tot += sign*stoi(equation.substr(i, j-i));
                sign = -1;
                i = j+1;
            }
        }
        // there may be a number in the end
        if (i < n) tot += sign*stoi(equation.substr(i));
        if (coeff == 0 && tot == 0) return "Infinite solutions";
        if (coeff == 0 && tot) return "No solution";
        int ans = -tot/coeff;
        return "x="+to_string(ans);
    }
};
