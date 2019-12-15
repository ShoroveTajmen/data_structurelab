
#include<iostream>
#include<stdlib.h>
using namespace std;
# define max 20
typedef struct dictionary {
   int d;
   struct dictionary *n;
} n_type;
n_type *p[max], *r[max], *t[max];
class Dict {
   public:
      int in;
      Dict();
      void insert(int);
      void search(int);
      void delete_element(int);
};
int main(int argc, char **argv) {
   int v, choice, n, num;
   char c;
   Dict d;
   do {
      cout << "\n1.Create";
      cout << "\n2.Search for a value";
      cout<<"\n3.Delete a value";
      cout << "\nEnter your choice:";
      cin >> choice;
      switch (choice) {
         case 1:
            cout << "\nEnter the number of elements to be inserted:";
            cin >> n;
            cout << "\nEnter the elements to be inserted:";
            for (int i = 0; i < n; i++) {
               cin >> num;
               d.insert(num);
            }
         break;
         case 2:
            cout << "\nEnter the element to be searched:";
            cin >> n;
            d.search(n);
         case 3:
            cout << "\nEnter the element to be deleted:";
            cin >> n;
            d.delete_element(n);
         break;
         default:
            cout << "\nInvalid choice....";
            break;
      }
      cout << "\nEnter y to continue......";
      cin >> c;
   }
   while (c == 'y');
}
Dict::Dict() {
   in = -1;
   for (int i = 0; i < max; i++) {
      r[i] = NULL;
      p[i] = NULL;
      t[i] = NULL;
   }
}
void Dict::insert(int k) {
   in = int(k % max);
   p[in] = (n_type*) malloc(sizeof(n_type));
   p[in]->d = k;
   if (r[in] == NULL) {
      r[in] = p[in];
      r[in]->n = NULL;
      t[in] = p[in];
   } else {
      t[in] = r[in];
      while (t[in]->n != NULL)
      t[in] = t[in]->n;
      t[in]->n= p[in];
   }
}
void Dict::search(int k) {
   int flag = 0;
   in= int(k % max);
   t[in] = r[in];
   while (t[in] != NULL) {
      if (t[in]->d== k) {
         cout << "\nSearch key is found!!";
         flag = 1;
         break;
      } else
         t[in] = t[in]->n;
   }
   if (flag == 0)
      cout << "\nsearch key not found.......";
}
void Dict::delete_element(int k) {
   in = int(k % max);
   t[in] = r[in];
   while (t[in]->d!= k && t[in] != NULL) {
      p[in] = t[in];
      t[in] = t[in]->n;
   }
   p[in]->n = t[in]->n;
   cout << "\n" << t[in]->d << " has been deleted.";
   t[in]->d = -1;
   t[in] = NULL;
   free(t[in]);
}
