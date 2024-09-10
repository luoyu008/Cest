#define _CRT_SECURE_NO_WARNINGS
////锯齿形层次遍历
//int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//    *returnSize = 0;
//    int** arr = (int**)malloc(sizeof(int*) * 2000);
//    int* columnSizes = (int*)malloc(sizeof(int) * 2000);
//    if (!root)
//        return NULL;
//    struct TreeNode* queue[2000];//=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
//    int front = 0;
//    int tail = 0;
//    queue[tail++] = root;
//    while (front != tail) {
//        arr[(*returnSize)] = (int*)malloc(sizeof(int) * (abs(front - tail)));
//        columnSizes[*returnSize] = abs(front - tail);
//        int head = front;
//        front = tail;;
//        for (int i = head; i < front; i++) {
//            arr[*returnSize][i - head] = queue[i]->val;
//            if (queue[i]->left) {
//                queue[tail++] = queue[i]->left;
//            }
//            if (queue[i]->right) {
//                queue[tail++] = queue[i]->right;
//            }
//        }
//        *returnSize += 1;
//    }
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
//    for (int i = 0; i < *returnSize; i++) {
//        (*returnColumnSizes)[i] = columnSizes[i];
//    }
//    for (int i = 0; i <= *returnSize; i++) {
//        if (i % 2 != 0) {
//            int left = 0;
//            int right = columnSizes[i] - 1;
//            while (left < right) {
//                int temp = 0;
//                temp = arr[i][left];
//                arr[i][left] = arr[i][right];
//                arr[i][right] = temp;
//                left++;
//                right--;
//            }
//        }
//    }
//    return arr;
//}
//
////二叉树的层次遍历
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//    *returnSize = 0;
//    int** arr = (int**)malloc(sizeof(int*) * 2000);
//    int* columnSizes = (int*)malloc(sizeof(int) * 2000);
//    if (!root)
//        return NULL;
//    struct TreeNode* queue[2000];//=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
//    int front = 0;
//    int tail = 0;
//    queue[tail++] = root;
//    while (front != tail) {
//        arr[(*returnSize)] = (int*)malloc(sizeof(int) * (abs(front - tail)));
//        columnSizes[*returnSize] = abs(front - tail);
//        int head = front;
//        front = tail;;
//        for (int i = head; i < front; i++) {
//            arr[*returnSize][i - head] = queue[i]->val;
//            if (queue[i]->left) {
//                queue[tail++] = queue[i]->left;
//            }
//            if (queue[i]->right) {
//                queue[tail++] = queue[i]->right;
//            }
//        }
//        *returnSize += 1;
//    }
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
//    for (int i = 0; i < *returnSize; i++) {
//        (*returnColumnSizes)[i] = columnSizes[i];
//    }
//    return arr;
//}