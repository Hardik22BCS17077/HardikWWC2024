class Solution {
public:
    vector<int> targetIndices(vector<int>& n, int t) {
        sort(n.begin(),n.end());
        vector<int>n1;
        int mid,p=-1;
        int l=0;
        int h=n.size();
        while(l<=h){
          mid=(l+h)/2;
          if(n[mid]==t)
          {
            p=mid;
            n1.push_back(p);
            break;
          }
          else if(n[mid]>t)
          {
              h= mid-1;
          }
          else{
              l= mid+1;
              }
        }
        if(n[mid]!=t){
            
            return n1;
        }
        if(n.size()==1 and n[mid]==t){
            return n1;
        }
      int r=mid;

      while(p>0){
          if(n[p]==n[p-1]){
          n1.push_back(p-1);
          p--;
          }
          else{
              break;
          }
      }
      while(r<n.size()-1){
          if(n[r]==n[r+1]){
          n1.push_back(r+1);
          r++;}
          else{
              break;
          }
      }
      sort(n1.begin(),n1.end());
      return(n1);
    }
};
