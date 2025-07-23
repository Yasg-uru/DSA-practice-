/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode* ptr=head;
        int left=0,right=n-1,top=0,bottom=m-1;
        int direction=0;
        while(top<=bottom and left<=right and ptr){
            if(direction==0){
                for(int col=left;col<=right and ptr ;col++){
                    ans[top][col]=ptr->val;
                    ptr=ptr->next;
                }
                top++;
            }else if(direction==1){
                for(int row=top;row<=bottom and ptr ;row++){
                    ans[row][right]=ptr->val;
                    ptr=ptr->next;
                }
                right--;
            }else if(direction==2){
                for(int col=right;col>=left and ptr;col--){
                    ans[bottom][col]=ptr->val;
                    ptr=ptr->next;
                }
                bottom--;
            }else if(direction==3){
                for(int row=bottom;row>=top and ptr;row--){
                    ans[row][left]=ptr->val;
                    ptr=ptr->next;

                }
                left++;
            }
            direction=(direction+1)%4;

        }
return ans;

    }
};