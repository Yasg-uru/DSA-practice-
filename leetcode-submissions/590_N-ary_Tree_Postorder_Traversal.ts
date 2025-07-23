/**
 * Definition for node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */
const postOrder=(root:_Node | null ,ans:number[]):void=>{
if(root==null){
    return ;
}
for(const child of root.children){
    postOrder(child,ans);
}
ans.push(root.val);
}
function postorder(root: _Node | null): number[] {
const ans:number[]=[];
postOrder(root,ans);
return ans;
};