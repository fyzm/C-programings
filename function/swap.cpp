/* 
//该函数既不交换指针，也不交换指针所指的内容
void SwapPointer1(int *p,int *q)
{
  int *tem = p;
  p = q;
  q = temp

}

void SwapPointer1(int *p,int *q)
{
  int tem = *p;
  *p = *q;
  q* = temp;

}
// 该函数交换指针本身的值,交换指针所指的内存地址
void SwapPointer3(int *&p,int *&q)
{
  int *temp = p;
  p = q;
  q = temp;
}




 */