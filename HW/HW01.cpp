#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void addPotion(int& HPPotion, int& MPPotion);



int main()
{
    srand((unsigned int)time(NULL));
    
    int status[7] = { 0 }; // 0 - HP / 1 - MP / 2 - 공격력 / 3 - 방어력 / 4 - 민첩 / 5 - 지능 / 6 - 정신력
    int selectMenu;
    int HPPotion = 0;
    int MPPotion = 0;
    int level = 1;

    cout << "HP와 MP를 입력해주세요 : ";
    cin >> status[0] >> status[1];
    while (1)
    {
        if (status[0] <= 50 && status[1] <= 50 )
        {
            cout << "HP와 MP는 50보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[0] >> status[1];
        }
        else if (status[0] <= 50 )
        {
            cout << "HP는 50보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[0];
        }
        else if (status[1] <= 50 )
        {
            cout << "MP는 50보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[1];
        }
        else
        {
            break;
        }

    }

    cout << "공격력과 방어력를 입력해주세요: ";
    cin >> status[2] >> status[3];
    while (1)
    {
        if (status[2] <= 0 && status[3] <= 0 )
        {
            cout << "공격력과 방어력는 0보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[2] >> status[3];
        }
        else if (status[2] <= 0 )
        {
            cout << "공격력는 0보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[2];
        }
        else if (status[3] <= 0 )
        {
            cout << "방어력는 0보다 커야합니다. 다시 입력해주세요." << endl;
            cin >> status[3];
        }
        else
        {
            break;
        }

    }
    
    status[4] = rand() % 100 +1;
    status[5] = rand() % 100 +1;
    status[6] = rand() % 100 +1;
    
    cout << "민첩 : " << status[4] << " 지능 : " << status[5] << " 정신력 : " << status[6] << endl;
    
    setPotion(5, &HPPotion, &MPPotion);
    cout << "포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;

    // 메뉴판
    while (1)
    {
        cout << "<스탯 관리 시스템>" << endl;
        cout << "================================" << endl;
        cout << "1.HP UP" << endl;
        cout << "2.MP UP" << endl;
        cout << "3.공격력 UP" << endl;
        cout << "4.방어력 UP" << endl; 
        cout << "5.현재 능력치" << endl;
        cout << "6.Level Up" << endl;
        cout << "0.나가기" << endl;
        cout << "번호를 선택해주세요 : ";
        cin >> selectMenu;
        
        switch (selectMenu)
        {
        case 0: 
            cout << "프로그램을 종료합니다." << endl;
            exit(0);
        
        case 1:
            if (HPPotion <= 0 )
            {
                cout << "HP포션이 부족합니다." << endl;
                break;
            }
            
            status[0] += 20;
            HPPotion--;
            
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP : " << status[0] << endl;
            cout << "남은 HP 포션 수 : " << HPPotion << endl;
            break;
            
        case 2:
            if (MPPotion <= 0 )
            {
                cout << "MP포션이 부족합니다." << endl;
                break;
            }
            
            status[1] += 20;
            MPPotion--;
            
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP : " << status[1] << endl;
            cout << "남은 MP 포션 수 : " << MPPotion << endl;
            break;
            
        case 3:
            status[2] *= 2;
            cout << "* 공격력이 2배로 증가되었습니다." << endl;
            cout << "현재 공격력 : "<< status[2] << endl;
            break;
            
        case 4:
            status[3] *= 2;
            cout << "* 방어력이 2배로 증가되었습니다." << endl;
            cout << "현재 방어력 : "<< status[3] << endl;
            break;
            
        case 5:
            cout << "현재 능력치" << endl;
            cout << "* HP : " << status[0] << " MP : " << status[1] << " 공격력 : " << status[2] << " 방어력 : " << status[3] << endl;
            cout << "+ 현재 레벨 : " << level << " 남은 HP/MP포션 개수 : " << HPPotion << "/" << MPPotion << endl;
            break;
            
        case 6:
            addPotion(HPPotion, MPPotion);
            level++;
            cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
            cout << "남은 HP/MP 포션 수 : " << HPPotion << "/" << MPPotion << endl;
            break;
            
        default:
            cout << "잘못된 값이 입력되었습니다. 다시 입력해주세요." << endl;
            break;
        }
        
    }
    
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void addPotion(int& HPPotion, int& MPPotion)
{
    HPPotion++;
    MPPotion++;
}