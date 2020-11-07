class Sort {
  public:
    Sort(int);
    void add(float); //<<--would be nice to have error checking to ensure that
                     //<<--the num_items < max_items
    virtual void sort(void)=0; //<<-means "pure" virtual
    void display(void);
    virtual ~Sort();
  protected:
    float* base;
    int num_items;
    const int max_items;
};

Sort::Sort(int no_items) 
  : num_items(0), 
    max_items(no_items), 
    base(new float[no_items])
{
}


class ToddsPartitionSort : public Sort{
  public:
    ToddsPartitionSort(int);
};

ToddsPartitionSort::ToddsPartitionSort(int no_items) : Sort(no_items)
{
}

int main()
{
  Sort* sp;
  cout << "What kind of sort would you like?" << endl;
  cout << "1) Partition" << endl;
  cout << "2) Heap" << endl;
  int choice;
  cin >> choice;
  if(choice==1)
    sp=new PartitionSort(99);
  if(choice==2)
    sp=new HeapSort(99);

  //for-loop
    sp->add(num_from_cin);
  sp->sort();
  sp->display();

  ToddsPartitionSort tps(10);
}
