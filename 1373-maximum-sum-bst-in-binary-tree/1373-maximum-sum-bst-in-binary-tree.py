# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class TreeProperties:
    def __init__(self):
        self.is_bst = True
        self.max_val = float('-inf')
        self.min_val = float('inf')
        self.max_sum = 0

class Solution:
    def __init__(self):
        self.max_sum_found = 0
        
    def _calculate_sums(self, node):
        if not node:
            return TreeProperties()
        
        left_props = self._calculate_sums(node.left)
        right_props = self._calculate_sums(node.right)
        
        current_props = TreeProperties()
        
        is_valid_bst = (
            left_props.is_bst and 
            right_props.is_bst and 
            node.val > left_props.max_val and 
            node.val < right_props.min_val
        )
        
        if is_valid_bst:
            current_props.is_bst = True
            current_props.max_sum = left_props.max_sum + right_props.max_sum + node.val
            current_props.min_val = min(node.val, left_props.min_val)
            current_props.max_val = max(node.val, right_props.max_val)
        else:
            current_props.is_bst = False
            current_props.max_sum = max(left_props.max_sum, right_props.max_sum)
            
        self.max_sum_found = max(self.max_sum_found, current_props.max_sum)
        
        return current_props

    def maxSumBST(self, root) -> int:
        self.max_sum_found = 0
        self._calculate_sums(root)
        return self.max_sum_found