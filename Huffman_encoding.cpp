#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HuffNode{
    string c;
    int f;
    HuffNode *lnxt;
    HuffNode *rnxt;
    
    HuffNode(string ch, int fr,HuffNode* vlnxt = nullptr,HuffNode *vrnxt = nullptr){
        c = ch;
        f = fr;
        lnxt = vlnxt;
        rnxt = vrnxt;
    }
};

template <typename T>
struct Node{
    T *data;
    Node *nxt;
    Node(T* d, Node* nnxt = nullptr){
        data = d;
        nxt = nnxt;
    }
    
    ~Node(){
        delete data;
    }
};

template <typename U>
class List{
    private:
        Node<U> *head;
        int _size;
    public:
        List(){
            head = nullptr;
            _size = 0;
        }
        
        ~List(){
            Node<U> *tmp = nullptr;
            while(head != nullptr){
                tmp = head;
                head = head->nxt;
                delete tmp;
            }
        }
        
        void add(U *data){
            Node<U> *newNode = new Node<U>(data);
            ++_size;
            if(head == nullptr){
                head = newNode;
            }
            else{
                Node<U> *tmp = head;
                Node<U> *tmp1 = nullptr;
                while(tmp){
                    if(tmp->data->f > newNode->data->f) break;
                    tmp1 = tmp;
                    tmp = tmp->nxt;
                }
                
                if(tmp1 == nullptr){
                    newNode->nxt = head;
                    head = newNode;
                }
                else{
                    newNode->nxt = tmp;
                    tmp1->nxt = newNode;
                }
            }
        }
        
        U *operator[] (int index){
            
            if(index >= _size) return nullptr;
            
            Node<U> *tmp = head;
            while(index){
                tmp = tmp->nxt;
                --index;
            }
            return tmp->data;
        }
        
        int size(){ return _size; }
};

HuffNode *builtHuffmanTree(List<HuffNode> &m_list){
    for(int i = 0; i < m_list.size(); i+=2){
        if(i == m_list.size()-1) return m_list[i];
        m_list.add(new HuffNode((m_list[i]->c + m_list[i+1]->c),(m_list[i]->f + m_list[i+1]->f),m_list[i],m_list[i+1]));
    }
}

string encode(HuffNode *root,string c,string en){
    if(root == nullptr) return "";
    
    if(root->c == c){
        return en;
    }
    
    string en_str = "";
    en_str = encode(root->lnxt,c,(en+"0"));
    if(en_str != "") return en_str;
    en_str = encode(root->rnxt,c,(en+"1"));
    if(en_str != "") return en_str;
    return en_str;
}

vector<pair<char,string>> HuffManEncoding(vector<pair<char,int>> vec){
    
    List<HuffNode> mlist;
    vector<pair<char,string>> encoded_list;
    HuffNode *hroot = nullptr;
    
    for(auto it : vec){
        mlist.add(new HuffNode(string(1,it.first),it.second));
    }
    
    hroot = builtHuffmanTree(mlist);
    
    /*
    for(int i = 0; i < mlist.size(); ++i){
        cout << "[ char = " << mlist[i]->c << " | freq: " <<  mlist[i]->f << "]" << endl;
    }*/
    
    for(auto it : vec){
        encoded_list.push_back(pair<char,string>(it.first,encode(hroot,string(1,it.first),"")));
    }
    
    return encoded_list;
}


int main()
{
    vector<pair<char,int>> vec;
    vec.push_back(pair<char,int>('a',5));
    vec.push_back(pair<char,int>('b',9));
    vec.push_back(pair<char,int>('c',12));
    vec.push_back(pair<char,int>('d',13));
    vec.push_back(pair<char,int>('e',16));
    vec.push_back(pair<char,int>('f',45));
    
    vector<pair<char,string>> encoded_list = HuffManEncoding(vec);
    
    for(auto it : encoded_list){
        cout << "[Encoded " << it.first << " = " << it.second << "] " <<endl;
    }
    
    return 0;
}

