#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    //holds value
    int val;
    //pointer to ListNode object
    ListNode* next;
    //default constructor
    ListNode() : val(0), next(nullptr) {}
    //constructor if there is a value given
    ListNode(int x) : val(x), next(nullptr) {}
    //constructor if there is a value and another ListNode object is given
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

int main()
{
    //input l1
    ListNode temp1(3);
    ListNode temp2(4, &temp1);
    ListNode input1(2, &temp2);
    ListNode* l1 = &input1;
    //inputl2
    ListNode temp3(4);
    ListNode temp4(6, &temp3);
    ListNode input2(5, &temp4);
    ListNode* l2 = &input2;

    //pointer to answer ListNode
    ListNode* answer = new ListNode();
    //pointer to iterate through answer
    ListNode* temp = answer;
    //container for carry-overs
    int carry = 0;
    //container for sum
    int sum = 0;
    //loop through whole of l1 and l2 and if there is a carry
    while (l1 != NULL || l2 != NULL || carry) {
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        //add carry to current sum
        sum += carry;
        //set new carry
        carry = sum / 10;
        //set current sum
        sum = sum % 10;
        temp->val = sum;
        //equal sum to 0 for next node
        sum = 0;
        //create next answer node if either l1 or l2 still has objects
        if (l1 != nullptr || l2 != nullptr || carry)
        {
            temp->next = new ListNode;
            temp = temp->next;
        }

    }

    while (answer != nullptr)
    {
        std::cout << answer->val;
        answer = answer->next;
    }



    return 0;

}
