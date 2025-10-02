int min(int a,int b){
    if(a>b)return b;
    else return a;
}
int maxArea(int* height, int heightSize) {
    int left=0;
    int right=heightSize-1;
    int high=min(height[left],height[right]);
    int max=(right-left)*high;
    if(high==height[left])left++;
    else right--;
    while(left<right){
        high=min(height[left],height[right]);
        int tmp=(right-left)*high;
        if(tmp>max)max=tmp;
        if(high==height[left])left++;
        else right--;
    }
    return max;
}
