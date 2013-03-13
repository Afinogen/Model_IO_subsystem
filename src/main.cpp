/*
 * main.cpp
 *
 *  Created on: 01.03.2013
 *      Author: Afinogen
 */
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include "lib\lib.h"
#include "function.h"


using namespace std;


UINT_PTR hTimer=NULL;     //указатель на таймер
int CountQuery;
Turn *pTurn;
Generator *pGenerator;
SubjectDrive *pSubjectDrive;
Valve *pSK1;
Valve *pSK2;
Collection *pCollection;
Time *pTime;
bool start;
int NextTimeQuery;

void InitSMO(int CountNMD)
{
	pTurn=new Turn();
	pGenerator=new Generator();
	pSubjectDrive=new SubjectDrive;
	pSubjectDrive->CreateCanal(CountNMD);
	pSK1=new Valve(pSubjectDrive);
	pSK2=new Valve(pSubjectDrive);
	NextTimeQuery=GetRand(0,20);
	pCollection=new Collection(1);
	pTime=new Time();
	start=true;
	CountQuery=CharToInt(pEditCountQuery->GetCaption());
}

void ClearSMO()
{
	start=false;
	delete pTurn;
	delete pGenerator;
	delete pSK1;
	delete pSK2;
	delete pSubjectDrive;
	delete pCollection;
	delete pTime;
}

//Функция таймера
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
	if (!start) return;

	setCursosPosition(0,0);
	if (NextTimeQuery<=0 && CountQuery>0)
	{
		pTurn->PutToContainer(pGenerator->CreateClient(GetRand(0,5),0));
		CountQuery--;
		NextTimeQuery=GetRand(1,20);
	}
	cout<<Rus("Кол-во заявок: ")<<CountQuery<<"	"<<Rus("Заявок в очереди: ")<<pTurn->SizeContainer()<<"		";
	string str;
	str.append(IntToChar(CountQuery));
	pEditCountQuery->setCaption(str.c_str());
	str="Заявок в очереди: ";
	str.append(IntToChar(pTurn->SizeContainer()));
	pLabelCountQueryTrun->setCaption(str.c_str());

	cout<<endl;
	if (pSK1->GetState()!=-1)
	{
		cout<<Rus("СК 1: занят НМД")<<(pSK1->GetState()+1)<<"	";
		str="СК 1: занят НМД";
		str.append(IntToChar(pSK1->GetState()+1));
		pLabelSK1->setCaption(str.c_str());
	}
	else
	{
		cout<<Rus("СК 1: свободен	");
		pLabelSK1->setCaption("СК 1: свободен");

		if (pTurn->SizeContainer()>0)
		{
			Client *pClient=NULL;
			for(int i=0;i<pTurn->SizeContainer();i++)
			{
				if (pSubjectDrive->GetCanal(pTurn->GetData(i)->GetPrioritet())->GetState()==false)
				{
					pClient=pTurn->GetData(i);
					break;
				}
			}

			if (pClient!=NULL)
			{
				setCursosPosition(0,1);
				pTurn->DelFrom(pClient);
				pSubjectDrive->GetCanal(pClient->GetPrioritet())->setClient(pClient,GetRand(1,30));
				cout<<Rus("СК 1: занят		");
				pLabelSK1->setCaption("СК 1: занят");
				pSK1->setState(-1);
			}

		}
	}

	if (pSK2->GetState()!=-1)
	{
		setCursosPosition(24,1);
		cout<<Rus("СК 2: занят НМД")<<(pSK2->GetState()+1)<<"	";
		str="СК 2: занят НМД";
		str.append(IntToChar(pSK2->GetState()+1));
		pLabelSK2->setCaption(str.c_str());
	}
	else
	{
		setCursosPosition(24,1);
		cout<<Rus("СК 2: свободен	");
		pLabelSK2->setCaption("СК 2: свободен");
		if (pTurn->SizeContainer()>0)
		{
				Client *pClient=NULL;
				for(int i=0;i<pTurn->SizeContainer();i++)
				{
					if (pSubjectDrive->GetCanal(pTurn->GetData(i)->GetPrioritet())->GetState()==false)
					{
						pClient=pTurn->GetData(i);
						break;
					}
				}

				if (pClient!=NULL)
				{
					setCursosPosition(24,1);
					pTurn->DelFrom(pClient);
					pSubjectDrive->GetCanal(pClient->GetPrioritet())->setClient(pClient,GetRand(1,30));
					cout<<Rus("СК 2: занят	");
					pLabelSK2->setCaption("СК 2: занят");
					pSK2->setState(-1);
				}

			}
	}

	cout<<endl;
	cout<<Rus("НМД1 ")<<pSubjectDrive->GetCanal(0)->GetState()
			<<Rus("	НМД2 ")<<pSubjectDrive->GetCanal(1)->GetState()
			<<Rus("	НМД3 ")<<pSubjectDrive->GetCanal(2)->GetState()
			<<Rus("	НМД4 ")<<pSubjectDrive->GetCanal(3)->GetState()
			<<Rus("	НМД5 ")<<pSubjectDrive->GetCanal(4)->GetState()
			<<Rus("	НМД6 ")<<pSubjectDrive->GetCanal(5)->GetState()<<endl;

	cout<<pSubjectDrive->GetCanal(0)->GetTimeStop()<<"	";
	pLabelTimeNMD1->setCaption(IntToChar(pSubjectDrive->GetCanal(0)->GetTimeStop()));

	cout<<pSubjectDrive->GetCanal(1)->GetTimeStop()<<"	";
	pLabelTimeNMD2->setCaption(IntToChar(pSubjectDrive->GetCanal(1)->GetTimeStop()));

	cout<<pSubjectDrive->GetCanal(2)->GetTimeStop()<<"	";
	pLabelTimeNMD3->setCaption(IntToChar(pSubjectDrive->GetCanal(2)->GetTimeStop()));

	cout<<pSubjectDrive->GetCanal(3)->GetTimeStop()<<"	";
	pLabelTimeNMD4->setCaption(IntToChar(pSubjectDrive->GetCanal(3)->GetTimeStop()));

	cout<<pSubjectDrive->GetCanal(4)->GetTimeStop()<<"	";
	pLabelTimeNMD5->setCaption(IntToChar(pSubjectDrive->GetCanal(4)->GetTimeStop()));

	cout<<pSubjectDrive->GetCanal(5)->GetTimeStop()<<"	";
	pLabelTimeNMD6->setCaption(IntToChar(pSubjectDrive->GetCanal(5)->GetTimeStop()));

	pSubjectDrive->DecTimeCanal();
	NextTimeQuery--;

	if (pSK1->GetState()==-1)
	{
		for(int i=0;i<6;i++)
		{
			if (pSubjectDrive->GetCanal(i)->GetState()==true
					&& pSubjectDrive->GetCanal(i)->GetTimeStop()==0
					&& pSubjectDrive->GetCanal(i)->GetClient()->GetType()==0)
			{
				if (pSubjectDrive->GetCanal(i)->GetClient()->GetType()==0)
				{
					pSubjectDrive->GetCanal(i)->GetClient()->setType(1);
					pSubjectDrive->GetCanal(i)->setTimeStop(GetRand(20,400));
					pSK1->setState(i);
					break;
				}
			}
		}
	}
	else
	{
		if (pSubjectDrive->GetCanal(pSK1->GetState())->GetClient()->GetType()==1
				&&
				pSubjectDrive->GetCanal(pSK1->GetState())->GetTimeStop()==0)
		{
			pCollection->PutToContainer(0,pSubjectDrive->GetCanal(pSK1->GetState())->GetClient());
			pSubjectDrive->GetCanal(pSK1->GetState())->DelClient();
			pSK1->setState(-1);
		}
	}

	if (pSK2->GetState()==-1)
	{
		for(int i=0;i<6;i++)
		{
			if (pSubjectDrive->GetCanal(i)->GetState()==true
					&& pSubjectDrive->GetCanal(i)->GetTimeStop()==0
					&& pSubjectDrive->GetCanal(i)->GetClient()->GetType()==0)
			{
				if (pSubjectDrive->GetCanal(i)->GetClient()->GetType()==0)
				{
					pSubjectDrive->GetCanal(i)->GetClient()->setType(1);
					pSubjectDrive->GetCanal(i)->setTimeStop(GetRand(20,400));
					pSK2->setState(i);
					break;
				}
			}
		}
	}
	else
	{
		if (pSubjectDrive->GetCanal(pSK2->GetState())->GetClient()->GetType()==1
				&&
				pSubjectDrive->GetCanal(pSK2->GetState())->GetTimeStop()==0)
		{
			pCollection->PutToContainer(0,pSubjectDrive->GetCanal(pSK2->GetState())->GetClient());
			pSubjectDrive->GetCanal(pSK2->GetState())->DelClient();
			pSK2->setState(-1);
		}
	}


	cout<<endl<<endl<<Rus("Обработано заявок: ")<<pCollection->GetCountAllClient();
	str="Обработано заявок: ";
	str.append(IntToChar(pCollection->GetCountAllClient()));
	pLabelCollectionClient->setCaption(str.c_str());

	pTime->IncTime();
	if (pSK1->GetState()!=-1) pSK1->IncTime();
	if (pSK2->GetState()!=-1) pSK2->IncTime();
	cout<<endl<<Rus("Общее время работы: ")<<pTime->GetTime()<<endl;
	str="Общее время работы: ";
	str.append(IntToChar(pTime->GetTime()));
	pLabelTimeWork->setCaption(str.c_str());

	double load_sk1=CutNumderDouble((static_cast<double>(pSK1->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	double load_sk2=CutNumderDouble((static_cast<double>(pSK2->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);

	cout<<Rus("Загрузка СК1: ")<<load_sk1<<"%	"<<endl;
	str="Загрузка СК1:  ";
	str.append(DoubleToChar(load_sk1));
	str.append("%");
	pLabelLoadSK1->setCaption(str.c_str());

	cout<<Rus("Загрузка СК2: ")<<load_sk2<<"%	"<<endl;
	str="Загрузка СК2:  ";
	str.append(DoubleToChar(CutNumderDouble(load_sk2,1)));
	str.append("%");
	pLabelLoadSK2->setCaption(str.c_str());

	cout<<Rus("Загрузка НМД")<<endl;
	double load_nmd1=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(0)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД1 ")<<load_nmd1<<"%	"<<endl;
	str="НМД1 ";
	str.append(DoubleToChar(load_nmd1));
	str.append("%");
	plabelLoadNMD1->setCaption(str.c_str());

	double load_nmd2=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(1)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД2 ")<<load_nmd2<<"%	"<<endl;
	str="НМД2 ";
	str.append(DoubleToChar(load_nmd2));
	str.append("%");
	plabelLoadNMD2->setCaption(str.c_str());

	double load_nmd3=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(2)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД3 ")<<load_nmd3<<"%	"<<endl;
	str="НМД3 ";
	str.append(DoubleToChar(load_nmd3));
	str.append("%");
	plabelLoadNMD3->setCaption(str.c_str());

	double load_nmd4=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(3)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД4 ")<<load_nmd4<<"%	"<<endl;
	str="НМД4 ";
	str.append(DoubleToChar(load_nmd4));
	str.append("%");
	plabelLoadNMD4->setCaption(str.c_str());

	double load_nmd5=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(4)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД5 ")<<load_nmd5<<"%	"<<endl;
	str="НМД5 ";
	str.append(DoubleToChar(load_nmd5));
	str.append("%");
	plabelLoadNMD5->setCaption(str.c_str());

	double load_nmd6=CutNumderDouble((static_cast<double>(pSubjectDrive->GetCanal(5)->GetTime())/static_cast<double>(pTime->GetTime()))*100,2);
	cout<<Rus("НМД6 ")<<load_nmd6<<"%	"<<endl;
	str="НМД6 ";
	str.append(DoubleToChar(load_nmd6));
	str.append("%");
	plabelLoadNMD6->setCaption(str.c_str());

	cout<<Rus("Среднее время обслуживания запроса: ");
	if (pCollection->GetAllTimeClinetInSystem()>0)
		cout<<static_cast<int>(pCollection->GetAllTimeClinetInSystem()/pCollection->GetCountAllClient());
	else cout<<"0";
	str="Среднее время обслуживания запроса: ";
	if (pCollection->GetAllTimeClinetInSystem()>0)
		str.append(IntToChar(pCollection->GetAllTimeClinetInSystem()/pCollection->GetCountAllClient()));
	else str.append("0");
	pLabelMidleTimeClinet->setCaption(str.c_str());

	if (CountQuery<=0 && pTurn->SizeContainer()==0 && pSubjectDrive->GetAllStateCanal()==false) //конец симуляции
		{
			KillTimer(hWnd,hTimer);
			hTimer=NULL;
			ClearSMO();
			pButtonStartPause->setCaption("Старт");
			//PostQuitMessage (0);
		}

	//cout<<endl<<GetNormalDistribution();
}

//Главная функция
int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nFunsterStil)
{
    MSG messages;            /* Here messages to the application are saved */

    InitForm(hThisInstance,nFunsterStil);

    CONSOLE_SCREEN_BUFFER_INFO info; // Для получения текущей позиции курсора

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // Это ты знаешь, зачем
    GetConsoleScreenBufferInfo(hCon, &info); // Получаем информацию о позиции курсора

    if (info.dwCursorPosition.Y==0) FreeConsole();
    else system("cls");
    //cout<<Rus("Введите количество запросов на обмен:");
    //cin>>CountQuery;
    //CountQuery=30;

    //system("cls");

    //hTimer=SetTimer(NULL,0, 50, &TimerProc); //запуск таймера

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK  WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

 	switch (message)                  /* handle the messages */
    {
    	case WM_PAINT:
    		hdc = BeginPaint(hwnd, &ps);

    		EndPaint(hwnd, &ps);
        break;
    	case WM_COMMAND:
    		if ((HWND)lParam == pButtonStartPause->GetHWNDElement() && hTimer==NULL)
    		{
    			 InitSMO(6);
    			 hTimer=SetTimer(NULL,0, 50, &TimerProc);
    			 pButtonStartPause->setCaption("Пауза");
    		}
    		else if ((HWND)lParam == pButtonStartPause->GetHWNDElement() && hTimer!=NULL)
    		{
    			 if (start)
    			 {
    				 start=false;
    				 pButtonStartPause->setCaption("Продолжить");
    			 }
    			 else
    			 {
    				 start=true;
    				 pButtonStartPause->setCaption("Пауза");
    			 }

    		}
    		if ((HWND)lParam == pButtonStop->GetHWNDElement())
    		{
    			if (hTimer!=NULL)
    			{
    				KillTimer(hwnd,hTimer);
    				Sleep(100);
    				hTimer=NULL;
    				ClearSMO();
    			}
    			pButtonStartPause->setCaption("Старт");
    		}

    	break;
    	case WM_CLOSE:
    		if (hTimer!=NULL) KillTimer(hwnd,hTimer);
    		//DestroyForm();
    		//hTimer=NULL;
    		//ClearSMO();
    		PostQuitMessage (0);
    	break;
    	case WM_DESTROY:
    		if (hTimer!=NULL) KillTimer(hwnd,hTimer);
    		DestroyForm();
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


