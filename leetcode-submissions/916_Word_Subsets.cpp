class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
      vector<int>maxfreq(26,0);
      for(string word:words2){
          vector<int>tempfreq(26,0);
          for(char ele:word ){
              tempfreq[ele-'a']++;
              maxfreq[ele-'a']=max(tempfreq[ele-'a'],maxfreq[ele-'a']);
          }
      }
          for(string word:words1){
              vector<int>wordfreq(26,0);
              for(char ele:word){
                  wordfreq[ele-'a']++;

              }
              bool isuniversal=true;
              for(int i=0;i<26;i++){
                  if(maxfreq[i]>wordfreq[i]){
                      isuniversal=false;
                      break;
                  }
              }
              if(isuniversal){
                  res.push_back(word);
              }
          }
      return res;
    }
};