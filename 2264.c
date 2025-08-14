char* largestGoodInteger(char* num) {
    int cnt=1;
    bool a[10]={false};
    char *ans=malloc(4);
    ans[3]='\0';
    ans[0]='\0';
    for(int i=1;i<strlen(num);i++){
        if(num[i]==num[i-1]){
            cnt++;
            if(cnt==3){
                a[num[i]-'0']=true;
            }
        }
        else cnt=1;
    }
    for(int j=9;j>=0;j--){
        if(a[j]){
            ans[0]=j+'0';
            break;
        }
    }
   if(ans[0] == '\0')return "";
    ans[1]=ans[0];
    ans[2]=ans[1];
    return ans;
}
