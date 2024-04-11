#include <stdio.h>
#include <stdlib.h>
int N,M,A[505][505],number[505][505];
long long K,sum,anser;
int main(int argc, char *argv[])
{
  scanf("%d%d%lld",&N,&M,&K);
  for(int i=1;i<=N;i++)//i,j从0开始，是因为后面有number[i-1][j],如果i从零开始，下标-1会越界
  {
    for(int j=1;j<=M;j++)
    {
      scanf("%d",&A[i][j]);
      number[i][j]=A[i][j]+number[i][j-1];//这个表达式表示序列前缀和，number[i][j]等于A[i][1]到A[i][j]的数字之和
    }
  }
  for(int k1=1;k1<=M;k1++)//k1表示矩阵起始那一列数字
  {
    for(int k2=k1;k2<=M;k2++)//k2表示矩阵边界的那一列数字
    {
      int r=1;
      sum=number[1][k2]-number[1][k1-1];//sum初始化
      for(int i=1;i<=N;i++)//i表示行数
      {
        while(sum<=K&&r<=N)
        {
          r++;//容纳的子矩阵行数+1
          sum+=number[r][k2]-number[r][k1-1];//统计r到i行，k2到k1列的矩阵数字之和
        }
        anser+=r-i;//为啥是r-i？表示的是r行到i行的子矩阵有r-i个
        sum-=number[i][k2]-number[i][k1-1];//因为i要加一，所以sun要减去i那一行的k2到k1的数字之和
      }
    }
  }
  printf("%ld",anser);
  return 0;
}
