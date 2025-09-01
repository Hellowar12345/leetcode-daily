typedef struct {
    int pass;
    int total;
    double gain;
} Node;

// 計算加一個學生後的增益
double calcGain(int pass, int total){
    return (double)(pass + 1)/(total + 1) - (double)pass/total;
}

// 交換兩個 Node
void swap(Node* a, Node* b){
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

// 下沉維護 max-heap
void heapifyDown(Node* heap, int size, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left].gain > heap[largest].gain) largest = left;
    if(right < size && heap[right].gain > heap[largest].gain) largest = right;

    if(largest != i){
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

// 建堆
void buildHeap(Node* heap, int size){
    for(int i = size/2 - 1; i >= 0; i--)
        heapifyDown(heap, size, i);
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents){
    Node* heap = (Node*)malloc(sizeof(Node)*classesSize);
    
    // 初始化 heap
    for(int i=0; i<classesSize; i++){
        heap[i].pass = classes[i][0];
        heap[i].total = classes[i][1];
        heap[i].gain = calcGain(heap[i].pass, heap[i].total);
    }

    buildHeap(heap, classesSize);

    // 分配學生
    for(int k=0; k<extraStudents; k++){
        // 取堆頂
        heap[0].pass++;
        heap[0].total++;
        heap[0].gain = calcGain(heap[0].pass, heap[0].total);
        // 下沉
        heapifyDown(heap, classesSize, 0);
    }

    // 計算平均
    double ans = 0.0;
    for(int i=0; i<classesSize; i++){
        ans += (double)heap[i].pass / heap[i].total;
    }

    free(heap);
    return ans / classesSize;
}
