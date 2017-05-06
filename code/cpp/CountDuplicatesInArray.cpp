map<int, int> blist;

 

void count_dup(int* arr, int start, int end)

{

    if(end == 0)

        blist[arr[start]]+=1;

 

    if(start<end) {

        if(arr[start] == arr[end]) {

            blist[arr[end]] += end - start + 1;

            return;

        }

 

        int mid = abs((start+end)/2);

        if(end - start == 2 && arr[start] < arr[mid] && arr[mid] < arr[end]) {

            blist[arr[start]] +=1;

            blist[arr[mid]] +=1;

            blist[arr[end]] +=1;

            return;

        }

 

        if(arr[start] != arr[mid] && start == mid) {

            blist[arr[start]]+=1;

            blist[arr[mid]] += 1;

            return;

        }

 

        if(arr[start] < arr[mid]) {

            count_dup(arr, start, mid);

        } 

        else {

            blist[arr[mid]] += mid - start + 1;

        }

        

        if(arr[mid+1] != arr[end] && mid+1 == end) {

            blist[arr[mid+1]]+=1;

            blist[arr[end]] += 1;

            return;

        }

        

 

        if(arr[mid+1] < arr[end]) {

            count_dup(arr, mid+1, end);

        }

        else {

            blist[arr[end]] += end - mid;

        }

    }

}

 

void main()

{

    int A[] = {1,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,6,7,7,8,9};

    count_dup(A, 0,20);

 

}
