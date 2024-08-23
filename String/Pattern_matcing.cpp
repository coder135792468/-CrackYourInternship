vector <int> search(string p, string t) {
            //code here.
            vector<int>ans;
            int n=t.size();
            int m=p.size();
             for (int i = 0; i <= n - m; i++) {
                if (t.substr(i, m) == p) {
                    ans.push_back(i+1);
                }
            }
            return ans;
}