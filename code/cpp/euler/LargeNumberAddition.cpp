int main()
{
    char line[55];
    short dignum[100][50];
    int count=0;
    ifstream myfile ("eulerinput.txt");

    for(int i=0 ; i<100; i++) {
        myfile.getline(line, 51);
        for(int j=0; j < 50; j++) {
            dignum[i][j] = line[j]-48;
            cout<<dignum[i][j];
        }
      cout<<endl;
    }

    int carry=0; // never >999.. since 100 digits addition + carry can never exceed over 999

    //adder
    int dsum;
    for(int i=49; i>=0; i--) {
      dsum = 0;
      for(int j=0; j < 100; j++) {
                  dsum += dignum[j][i];
      }
      dsum += carry;
      carry = dsum/10;
      cout<<dsum%10<<" "; //digits in reverse
    }
    cout<<endl<<dsum;

    return 0;
}
