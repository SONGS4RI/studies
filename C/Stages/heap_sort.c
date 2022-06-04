#define MAX_ELEMENT 200 // 힙 안에 저장된 요소의 개수

typedef struct{
  int key;
} element;

typedef struct{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;


HeapType heap1;
// 최대 힙(max heap) 삽입 함수
void insert_max_heap(HeapType *h, element item){
  int i;
  i = ++(h->heap_size); 

  while((i != 1) && (item.key > h->heap[i/2].key)){
    h->heap[i] = h->heap[i/2];
    i /= 2;
  }
  h->heap[i] = item; 
}
// 최대 힙(max heap) 삭제 함수
element delete_max_heap(HeapType *h){
  int parent, child;
  element item, temp;

  item = h->heap[1]; 
  temp = h->heap[(h->heap_size)--]; 
  parent = 1;
  child = 2;

  while(child <= h->heap_size){
    if( (child < h->heap_size) && ((h->heap[child].key) < h->heap[child+1].key) ){
      child++;
    }
    if( temp.key >= h->heap[child].key ){
      break;
    }

    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }

  h->heap[parent] = temp;
  return item;
}

// 우선순위 큐인 힙을 이용한 정렬
void heap_sort(element a[], int n){
  int i;
  HeapType h;

  init(&h);

  for(i=0; i<n; i++)
  {
    insert_max_heap(&h, a[i]);
  }

  for(i=(n-1); i>=0; i--)
  {
    a[i] = delete_max_heap(&h);
  }
}