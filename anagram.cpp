bool isAnagram(string a, string b){
        vector<int> vec(26,0);
        for(char c : a) vec[c-'a']++;
        for(char c1 : b) vec[c1-'a']--;
        for(int i=0;i<26;i++){
            if(vec[i] != 0) return false;
        }
        return true;
    }
