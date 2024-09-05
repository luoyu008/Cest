#define _CRT_SECURE_NO_WARNINGS
//消除字符串
//char* clearDigits(char* s) {
//    int len = strlen(s);
//    char* str = (char*)malloc(sizeof(char) * (len + 1));
//    int j = 0;
//    if (len == 0)
//        return NULL;
//    for (int i = 0; i < len; i++) {
//        if (s[i] < '0' || s[i]>'9') {
//            str[j] = s[i];
//            j++;
//        }
//        else {
//            j--;
//        }
//    }
//    str[j] = '\0';
//    return str;
//}


//二叉树中序遍历
//int* MID(struct TreeNode* root, int* str, int* returnSize) {
//    if (root == NULL) {
//        return NULL;
//    }
//    MID(root->left, str, returnSize);
//    str[(*returnSize)++] = root->val;
//    MID(root->right, str, returnSize);
//    return str;
//}
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    int* str = (int*)malloc(sizeof(int) * 2000);
//    *returnSize = 0;
//    MID(root, str, returnSize);
//    return str;
//}
					

//对称二叉树判断
//bool JUDGE(struct TreeNode* t1, struct TreeNode* t2) {
//    if (t1 == NULL && t2 == NULL) {
//        return true;
//    }
//    if (t1 == NULL || t2 == NULL)
//        return false;
//    if (t1->val != t2->val) {
//        return false;
//    }
//    return JUDGE(t1->left, t2->right) && JUDGE(t1->right, t2->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//    return JUDGE(root->left, root->right);
//}


//相同的树判断
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL) {
//        return true;
//    }
//    // 如果一个节点为 NULL，另一个不为 NULL，返回 false  
//    if (p == NULL || q == NULL) {
//        return false;
//    }
//    // 比较当前节点的值  
//    if (p->val != q->val) {
//        return false;
//    }
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

//二叉树的最大深度
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//    int deep1 = maxDepth(root->left);
//    int deep2 = maxDepth(root->right);
//    int max = deep1 > deep2 ? deep1 : deep2;
//    return max + 1;
//
//}