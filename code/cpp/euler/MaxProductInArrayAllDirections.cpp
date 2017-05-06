using namespace std;
 
void main()
{
    char line[10];
    double arr[20][20];
    ifstream myfile ("C:\\Works\\cppassignments\\algorithms\\algorithms\\euler-input.txt");
 
    for(int i =0 ; i<20; i++) {
        for(int j=0; j<20; j++) {
            myfile.getline(line, 10, ' ');
            arr[i][j] = atof(line);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 
    double max=1;
    double prod;
 
    // rows
    for(int i=0;i<20; i++) {
        for(int j=0; j<17; j++) {
            prod = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
            if(max < prod) {
                max = prod;
            }
        }
    }
 
    // column
    for(int j =0; j<20;j++) {
        for(int i=0;i<17; i++) {
            prod = arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
            if(max < prod) {
                max = prod;
            }
        }
    }
 
    // diagonal right top to bottom left
    // exclude 3 from 20 as it never can make it to 4 elements
    for(int i=0; i< 17;i++) {
        for(int j=0; j<17;j++) {
            prod = arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            if(max < prod)
                max = prod;
        }
    }
 
    // diagonal left top to right bottom
    for(int i=3; i< 20;i++) {
        for(int j=0; j<17;j++) {
            prod = arr[i][j]*arr[i-1][j+1]*arr[i-2][j+2]*arr[i-3][j+3];
            if(max < prod)
                max = prod;
        }
    }
}
