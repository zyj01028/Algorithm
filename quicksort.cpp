void quick_sort(int a[], int i_left, int j_right)
{
    int x=a[i_left];

    int i=i_left;
    int j=j_right;

    if(i_left>j_right)
       return;


    while(i<j)
   {
       while(a[j]>=x&&i<j)
        j--;
       while(a[i]<=x&&i<j)
        i++;

       int tmp;
       if(i<j)
       {
           tmp=a[i];
           a[i]=a[j];
           a[j]=tmp;
       }
   }
   a[i_left]=a[i];
   a[i]=x;

   quick_sort(a,i_left,i-1);
   quick_sort(a,i+1,j_right);
}



//快排中找第k小数
/*
快速排序求第k小的数，思想非常简单，就是如果要查找的k比当前下标i小，则只递归左部分，大则递归右部分，相等则递归右部分。
当然由于数组下标从0开始，所以应该是k-1,（比如第一大的数数组下标为0)，原理就是快速排序是以一个元素为分隔的，
如果求第k大的元素，就是求第n-k+1小的元素
*/
void quick_sort(vector<int> &input,const int left,const int right,const int k)
{
    int x=input[left];
    int i=left;
    int j=right;

    if(left>right)
        return;
    while(i<j)
    {
        while(input[i]<=x&&i<j)
            i++;
        while(input[j]>=x&&i<j)
            j--;

        int tmp;
		
        if(i<j)
        {
            tmp=input[i];
            input[i]=input[j];
            input[j]=tmp;
        }

        input[left]=input[i];
        input[i]=x;

        if(i<k-1)
            quick_sort(input,i+1,right,k);
        else
            quick_sort(input,left,i-1,k);

    }
}
