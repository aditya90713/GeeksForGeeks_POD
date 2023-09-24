class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        // int n = nums.size();
     unordered_map<int, int> map;

        vector<int> res;
        for(int i = 0 ; i < n; i++){
                map[arr[i]]++;
        }
        for(auto i : map){
            if(i.second > 1){
                res.push_back(i.first);
            }
        }
        if(res.size() > 0){
            sort(res.begin(), res.end());
            return res;
        }
        res.push_back(-1);
        return res;
    }
};