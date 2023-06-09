#include<iostream>
using namespace std;
struct Student
{
    int roll_no;
    string name;
    float sgpa;
};
void Input(struct Student s[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Name:";
        cin>>s[i].name;
        cout<<"Enter the Roll_no:";
        cin>>s[i].roll_no;
        cout<<"Enter the SGPA:";
        cin>>s[i].sgpa;
    }
}
void Display(struct Student s[],int n)
{
    cout<<"Roll_NO"<<"\t"<<"Name\t"<<"SGPA\n";
    for(int i=0;i<n;i++)
    {
        cout<<s[i].roll_no<<"\t"<<s[i].name<<"\t"<<s[i].sgpa<<"\n";
    }
}
void BubbleSort(struct Student s[],int n)
{
    struct Student temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(s[j+1].roll_no<s[j].roll_no)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void InsersionSort(struct Student s[],int n)
{
    struct Student temp;
    for(int i=1;i<n;i++)
    {
        temp=s[i];
        string temp1=s[i].name;
        int j=i-1;
        while(j>=0)
        {
            if(s[j].name>temp1)
            {
                s[j+1]=s[j];
            }
            else
            break;
            j--;
        }
        s[j+1]=temp;
    }
}
void quick_sort(struct Student s[],int first ,int last)
{
int i,j,pivot;
struct Student temp;
	if(first<last)
	{
        pivot=first;
        i=first+1;
        j=last;
		while(i<=j)
		{
			while(s[i].sgpa>=s[pivot].sgpa)
		    i++;
			while(s[j].sgpa<s[pivot].sgpa)
		    j--;
			if(i<j)
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
		temp=s[pivot];
		s[pivot]=s[j];
		s[j]=temp;

		quick_sort(s,first,j-1);
		quick_sort(s,j+1,last);
	}
}

void toppers(struct Student s[],int n)
{
	int i;
	cout<<"The toppers are:";
	cout<<"\n"<<"Name "<<"\t"<<"Roll no."<<"\t"<<"Sgpa"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<s[i].name<<"\t"<<s[i].roll_no<<"\t"<<s[i].sgpa<<endl;
		}
}

void BinarySearch(struct Student s[],int n)
{
    InsersionSort(s,n);
    int low,high,mid;
    low=0;
    high=n-1;
    string Name;
    cout<<"Enter the name to Search:";
    cin>>Name;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(s[mid].name==Name)
        {
            cout<<"Record is Found!!";
            cout<<s[mid].name<<"\t"<<s[mid].roll_no<<"\t"<<s[mid].sgpa<<endl;
            return ;
        }
        else if(s[mid].name>Name)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        
        
    }cout<<"NOT FOUND"<<endl;
}
int main()
{
    int n;
    cout<<"Enter thr number of Records you want to store:";
    cin>>n;
    struct Student s[n];
    Input(s,n);
    int choice;
    do
    {
        cout<<"Enter the operation you want to perform:\n1)Bubble Sort\n2)Insertion Sort\n3)Quick Sort\n4)Binary Search\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"bubble sort\n";
            BubbleSort(s,n);
            Display(s,n);
            break;

            case 2:
            cout<<"insertion sort\n";
            InsersionSort(s,n);
            Display(s,n);
            break;

            case 3:
            cout<<"Quick sort\n";
            quick_sort(s,0,n-1);
            toppers(s,n);
            break;

            case 4:
            cout<<"binary search\n";
            BinarySearch(s,n);
            break;
        }
    } while (choice !=5);
    return 0;
}