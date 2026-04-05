// Last updated: 4/5/2026, 11:43:24 AM
class Solution {
public:
void strcpy(char* a,char* b){
    for(int i=0;b[i]!='\0';i++){
        *(a+i)=*(b+i);
    }
}
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int max,temp;
        char tname[100];
        for(int i=0;i<heights.size();i++){
            max=i;
            for(int j=i+1;j<names.size();j++){
                if(heights[max]<heights[j])
                max=j;
            }

                swap(heights[max],heights[i]);
                swap(names[max],names[i]);
            // temp=heights[max];
            // heights[max]=heights[i];
            // heights[i]=temp;
            
            //  strcpy(tname,names[max]);
            //  strcpy(names[max],names[i]);
            //  strcpy(names[i],tname);



            
        }
        return names;
    }
};