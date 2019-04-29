#include<iostream>
using namespace std;

typedef struct tree
{
    int number;
    struct tree *leftChild;
    struct tree *rightChild;
} node;

node *root=NULL;

void insertNode(int value);
void searchOnTree(int value);
void preOrderPrint(node *rootNode);
void inOrderPrint(node *rootNode);
void postOrderPrint(node *rootNode);

void insertNode(int value) // ini berfungsi untuk memasukan node ke dalam pohon
{
    node *tempNode;
    node *currentNode;
    node *parentNode;

    tempNode = (node *) malloc(sizeof(node));
    tempNode->number = value;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    //untuk kelas pertama
    if(root==NULL)
    {
        root = tempNode;
    }
    else
    {
        currentNode = root;
        parentNode = NULL;

        while(1)
        {
            parentNode = currentNode;

            if(value <= parentNode->number)
            {
                currentNode = currentNode->leftChild;

                if(currentNode==NULL)
                {
                    parentNode->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                currentNode = currentNode->rightChild;

                if(currentNode==NULL)
                {
                    parentNode->rightChild = tempNode;
                    return;
                }
            }

        }
    }
}


void searchOnTree(int value) // ini Berfungsi untuk mencari node di dalam pohon
{
    node *currentNode = root;
    int flag = 0;

    while(1)
    {
        if(value == currentNode->number)
        {
            flag = 1;
            break;
        }
        else if(value<=currentNode->number)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;

        if(currentNode==NULL)
            break;

    }

    if(flag==1)
        cout << currentNode->number <<" Ada Di Dalam Pohon.";
    else
        cout << value <<" Tidak Ada Di Dalam Pohon." ;
}


void preOrderPrint(node *rootNode)// ini berfungsi untuk mencetak preorder pohon
{
    if(rootNode==NULL)
        return;

    cout<<" "<< rootNode->number;

    preOrderPrint(rootNode->leftChild);
    preOrderPrint(rootNode->rightChild);
}


void inOrderPrint(node *rootNode)// ini berfungsi untuk mencetak inorder pohon
{
    if(rootNode==NULL)
        return;

    inOrderPrint(rootNode->leftChild);

    cout << " " << rootNode->number;

    inOrderPrint(rootNode->rightChild);
}


void postOrderPrint(node *rootNode)// ini berfungsi untuk mencetak postorder pohon
{
    if(rootNode==NULL)
        return;

    postOrderPrint(rootNode->leftChild);
    postOrderPrint(rootNode->rightChild);

    cout << " " << rootNode->number ;

}


int main()// Fungsi utama 
{
	int pil, flag=1, value;

cout<<"||=====================================================||"<<endl;
cout<<"||               Implementasi ADT Tree                 ||"<<endl;
cout<<"||               DEVELOPED BY BulinMcD                 ||"<<endl;
cout<<"||=====================================================||"<<endl<<endl;
cout<<"Menu Program :";
 while( flag == 1){
cout<<"\n==================\n";
cout<<"1.Masukan Node \n";
cout<<"2.Cetak PreOrder \n";
cout<<"3.Cetak InOrder \n";
cout<<"4.Cetak PostOrder \n";
cout<<"5.Cari Node \n";
cout<<"6.Keluar \n";
cout<<"====================\n";
cout<<"Pilih : ";cin>>pil;
cout<<"====================";
cout<<endl<<endl;
	switch (pil)//Program Menu menggunakan Switch
	{
	case 1: cout<<"Masukan Node: ";
			cin>>value;
			insertNode(value);
			break;
	case 2: preOrderPrint(root);
			break;
	case 3: inOrderPrint(root);
			break;
	case 4: postOrderPrint(root);
			break;
	case 5: cout<<"Masukan Yang Ingin Di Cari: ";
			cin>>value;
			searchOnTree(value);
			break;
	case 6: flag = 0;
			cout << endl << endl;
			break;
         
 }
 }
    return 0;
}

