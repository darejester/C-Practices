#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct ListNode {
    //holds value
    int val;
    //pointer to ListNode object
    ListNode *next;
    //default constructor
    ListNode() : val(0), next(nullptr) {}
    //constructor if there is a value given
    ListNode(int x) : val(x), next(nullptr) {}
    //constructor if there is a value and another ListNode object is given
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
};

int main()
{
    //input l1
    ListNode temp1(3);
    ListNode temp2(4, &temp1);
    ListNode l1(2, &temp2);
    //inputl2
    ListNode temp3(4);
    ListNode temp4(6, &temp3);
    ListNode l2(5,&temp4);

    //container for final answer
    ListNode answer;
    //pointers towards nodes
    ListNode* ptr1 = &l1;
    ListNode* ptr2 = &l2;
    ListNode* ptr3 = &answer;
    ListNode* ptr4 = &answer;
    //holds value for any carry-overs
    int carry = 0;
    //hold sum of vals
    int sum = 0;

    //go through all linked list
    while (ptr1 != nullptr || ptr2 != nullptr)
    {
        //add nodes and any carry-overs
        sum = ptr1->val + ptr2->val + carry;
        //check if there is any carry-overs for next node
        if (sum > 9)
        {
            carry = 1;
            sum = sum - 10;
        }
        //set sum as the value of the node in answer
        ptr3->val = sum;
        //check if there are any other nodes to be added
        if (ptr1->next != nullptr || ptr2->next != nullptr)
        {
            //add new node to answer
            ptr3->next = new ListNode;
            ptr3 = ptr3->next;
        }
        //check if there are more nodes left in any list
        if (ptr1 != nullptr)
        {
            //move pointers to next node
            ptr1 = ptr1->next;
            
        }
        if (ptr2 != nullptr)
        {
            ptr2 = ptr2->next;
        }
        


    }
    while (ptr4 != nullptr)
    {
        std::cout << ptr4->val;
        ptr4 = ptr4->next;
    }

    //std::cout << answer.next << std::endl;

}
