
#include <stdafx.h>
#include "Fixture.h"

void CFixture::ClearDates()
{
	int count = m_teams.GetCount();

	for (int i = 0; i < count; i++)
		m_teams.GetAt(i).m_dates.RemoveAll();
}

void CFixture::ClearDate(int date)
{
	int count = m_teams.GetCount();

	for (int i = 0; i < count; i++)
		if ((m_teams.GetAt(i).m_dates.GetCount()-1) == date)
			m_teams.GetAt(i).m_dates.RemoveAt(date);

	if (!CheckDates())
	{
		MessageBox(NULL, "Error Found", "Debug", MB_OK);
	}
}

int OverAdd(int num, int offset, int max)
{
	num += offset;

	while (num >= max)
		num -= max;

	return num;
}

int OverSubtract(int num, int offset, int max)
{
	num -= offset;

	while (num < 0)
		num += max;

	return num;
}

bool IsInArray(int num, CUIntArray& disallowed)
{
	int count = disallowed.GetCount();

	for (int i = 0; i < count; i++)
		if (disallowed.GetAt(i) == num)
			return true;

	return false;
}

bool AreInParallelLists(int numA, int numB, CUIntArray& listA, CUIntArray& listB)
{
	int count = listA.GetCount();

	for (int i = 0; i < count; i++)
	{
		if (listA.GetAt(i) == numA && listB.GetAt(i) == numB)
			return true;
	}

	return false;
}

bool AreInParallelListsI(int numA, int numB, CUIntArray& listA, CUIntArray& listB)	//Lists interchangeable
{
	int count = listA.GetCount();

	int a, b;

	for (int i = 0; i < count; i++)
	{
		a = listA.GetAt(i);
		b = listB.GetAt(i);

		if ((a == numA && b == numB) || (b == numA && a == numB))
			return true;
	}

	return false;
}

int SecureOverSubtract(int num, int offset, int max, CUIntArray& disallowed)
{
	num -= offset;

	while (num < 0)
		num += max;

	if (disallowed.GetCount() == max)
		return num;		//Failed

	while (IsInArray(num, disallowed))
		num = OverSubtract(num, 1, max);

	disallowed.Add(num);

	return num;
}

int SecureOverAdd(int num, int offset, int max, CUIntArray& disallowed)
{
	num += offset;

	while (num >= max)
		num -= max;

	if (disallowed.GetCount() == max)
		return num;		//Failed

	while (IsInArray(num, disallowed))
		num = OverAdd(num, 1, max);

	disallowed.Add(num);

	return num;
}

void CTeam::DumpTeam(CString name)
{
	CString teamstr = "";

	int count = m_dates.GetCount();

	for (int i = 0; i < count; i++)
		teamstr += (CString)(char)('A'+m_dates.GetAt(i)) + "\n";

	MessageBox(NULL, teamstr, name, MB_OK);
}

bool CFixture::CheckAddMatch(int teamA, int teamB, int date)
{
	//int a, b;

	if (teamB != teamA && !m_teams.GetAt(teamA).WasPlayed(teamB) && !IsPlaying(date, teamB) && !IsPlaying(date, teamA))
	{
		/*a = */m_teams.GetAt(teamA).m_dates.Add(teamB);
		/*b = */m_teams.GetAt(teamB).m_dates.Add(teamA);

		/*if ((a != date) || (b != date))
			MessageBox(NULL, "Added other date: " + ConvertIntToString(a) + " / " + ConvertIntToString(b) + " in " + ConvertIntToString(date), "Debug", MB_OK);*/
		return true;
	}
	
	return false;
}

bool CFixture::CheckDates()
{
	int count = m_teams.GetCount();
	int date = 0;

	for (int i = 0; i < count; i++)
	{
		if (!i)
			date = m_teams.GetAt(i).m_dates.GetCount();
		else
			if (m_teams.GetAt(i).m_dates.GetCount() != date)
				return false;
	}

	return true;
}

void CFixture::DumpTeamDates(CString caption, bool filedump)
{
	int count = m_teams.GetCount();

	CString strtp = "";

	for (int i = 0; i < count; i++)
		strtp += "\t" + ((CString)(char)('A'+i));

	strtp += "\n";

	bool added = false;
	bool addedB = false;

	for (int i = 0; ; i++, added = addedB = false)
	{
		for (int j = 0; j < count; j++)
		{
			if (!added)
			{
				strtp += "\n" + ConvertIntToString(i) + ":";
				added = true;
			}

			if (m_teams.GetAt(j).m_dates.GetCount()-1 >= i)
			{
				addedB = true;
				strtp += "\t" + ((CString)(char)('A'+m_teams.GetAt(j).m_dates.GetAt(i)));
			}
			else
				strtp += "\t";
		}

		if (!addedB)
		{
			strtp += "(X)";
			break;
		}
	}

	if (filedump)
	{
		CFile file("C:\\Dump.txt", CFile::modeWrite | CFile::modeCreate);
		file.Write(strtp, strtp.GetLength());
		file.Close();
	}

	MessageBox(NULL, strtp, caption, MB_OK);
}

void CFixture::CheckConsistency(int dateB, int start, int offset, int a, int b, int c, bool secure)
{
	int count = m_teams.GetCount();
	int date = 0;
	bool first = true;

	for (int i = 0; i < count; i++)
	{
		if (!i)
			date = m_teams.GetAt(i).m_dates.GetCount();
		else
			if (date - m_teams.GetAt(i).m_dates.GetCount())
			{
				if (first)
				{
					MessageBox(NULL, ConvertIntToString(dateB) + " " + ConvertIntToString(start) + " " + ConvertIntToString(offset) + " " + ConvertIntToString(a) + " " + ConvertIntToString(b) + " " + ConvertIntToString(c) + (secure?((CString)" Secure"):((CString)" Non Secure")), "Debug Info", MB_OK);
					first = false;
				}

				MessageBox(NULL, ConvertIntToString(date) + " " + ConvertIntToString(m_teams.GetAt(i).m_dates.GetCount()) + "(" + ConvertIntToString(i) + ")", "Debug", MB_OK);
			}
	}
}

bool CFixture::CalcTeam(int date, int teamA, int count, int start, int offset, bool secure)
{
	CUIntArray tested;

	if ((m_teams.GetAt(teamA).m_dates.GetCount() - 1) < date)
	{
		int k, l;

		if (m_progress8)
			m_progress8->SetPos(0);

		for (k = start, l = 0; l < count; l++, (secure?(k=SecureOverAdd(k, offset, count, tested)):(k=OverAdd(k, offset, count))))	//Select TeamB
		{
			if (CheckAddMatch(teamA, k, date))
				break;

			if (m_progress8)
				m_progress8->SetPos(l+1);
		}

		if (l == count)
		{
			/*if (date == 16 && start == 0 && offset == 1 && !secure)
			{
				for (int p = 0; p < m_teams.GetCount(); p++)
					m_teams.GetAt(p).DumpTeam((CString)(char)('A'+p));
				MessageBox(NULL, "Done", "Separator", MB_OK);
			}*/

			ClearDate(date);
			return false;
		}
	}

	return true;
}

bool CFixture::CalcDate(int date, int count, int start, int offset, bool secure, bool carry)
{
	CUIntArray disallowed;

	int j, l, k;

	bool loop = true;

	if (m_progress5)
		m_progress5->SetPos(0);

	for (int k = 0; loop && k < count; k++)	//TeamB Start
	{
		if (m_progress6)
			m_progress6->SetPos(0);

		for (int i = 1; loop && i < count; i++)	//TeamB Offset
		{
			loop = false;

			disallowed.RemoveAll();

			if (m_progress7)
				m_progress7->SetPos(0);

			for (j = start, l = 0; l < count; l++, j = SecureOverAdd(j, offset, count, disallowed))
				if (!CalcTeam(date, j, count, k, i, secure))
				{
					loop = true;
					if (!carry)
						break;
				}
				else
					if (m_progress7)
						m_progress7->SetPos(l+1);

			/*if (date == 16 && start == 0 && offset == 1 && k == 0 && i == 1 && !secure)
			{
				for (int p = 0; p < m_teams.GetCount(); p++)
					m_teams.GetAt(p).DumpTeam((CString)(char)('A'+p));
				MessageBox(NULL, "Done", "Separator", MB_OK);
			}*/

			//if (!loop)
			//	MessageBox(NULL, "Date " + ConvertIntToString(date), "Done", MB_OK);
			
			if (!carry && !CheckDates())
			{
				ClearDate(date);
				loop = true;
			}

			/*if (date == 16 && start == 0 && offset == 1 && k == 0 && i == 1 && !secure)
			{
				for (int p = 0; p < m_teams.GetCount(); p++)
					m_teams.GetAt(p).DumpTeam((CString)(char)('A'+p));
				MessageBox(NULL, "Done", "Separator", MB_OK);
			}*/

			if (!carry)
				CheckConsistency(date, start, offset, k, i, j, secure);

			/*if (!loop)
				if (MessageBox(NULL, "Date " + ConvertIntToString(date) + " done at k = " + ConvertIntToString(k) + ", i = " + ConvertIntToString(i) + " & j = " + ConvertIntToString(j), "Debug", MB_YESNO) == IDYES)
				{
					for (int p = 0; p < m_teams.GetCount(); p++)
						m_teams.GetAt(p).DumpTeam((CString)(char)('A'+p));
					MessageBox(NULL, "Done", "Separator", MB_OK);
				}*/

			if (m_progress6)
				m_progress6->SetPos(i+1);
		}

		if (m_progress5)
			m_progress5->SetPos(k+1);
	}

	if (loop)
		return false;

	if (carry && !CheckDates())
	{
		ClearDate(date);

		if (m_teams.GetAt(0).m_dates.GetCount() - 1 != date)
			return false;
		else
			return true;
	}

	return true;
}

/*bool CFixture::CalcTeamDates(int count, int date, int startingteam, int offset)
{
	bool errchk;

	int j, k;

	CUIntArray tested;

	for (j = startingteam, k = 0; k < count && !(errchk = CalcDate(j, count, date)); j = SecureOverAdd(j, offset, count, tested), k++)
		;

	if (!errchk)
		return false;

	return true;
}*/

int Reduce(int numtr, int maxnumNI)
{
	/*while (numtr >= maxnumNI)
		numtr -= maxnumNI;*/

	return numtr%maxnumNI;
}

int GetPossibleMatches(int num)
{
	int result = num*num;

	for (int i = 1; i < num; i++)
		result -= i;

	return result - num;	//Take out A vs A
}

void DumpLists(CUIntArray& a, CUIntArray& b)
{
	int count;

	if ((count = a.GetCount()) != b.GetCount())
		return;

	CString dumptxt = "";

	for (int i = 0; i < count; i++)
		dumptxt += ConvertIntToString(a.GetAt(i)) + " - " + ConvertIntToString(b.GetAt(i)) + "\n";

	MessageBox(NULL, dumptxt, "Lists Dump", MB_OK);
}

int GeneratePossibleMatches(int count, CUIntArray& a, CUIntArray& b)
{
	int items = 0;

	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (i < j)
			{
				items++;
				a.Add(i);
				b.Add(j);
			}
	
	return items;
}

bool CFixture::Calculate()
{
	CFile fileS("C:\\Started.chk", CFile::modeCreate);
	fileS.Close();

	ClearDates();

	int count = m_teams.GetCount();

	bool errchk = false;

	if (m_progress1)
		m_progress1->SetRange(0, (m_bEnableA1?1:0)+(m_bEnableA2?1:0)+(m_bEnableA3?1:0)+(m_bEnableRG?1:0));
	if (m_progress2)
		m_progress2->SetRange(0, count - 1);
	if (m_progress3)
		m_progress3->SetRange(0, count);
	if (m_progress4)
		m_progress4->SetRange(0, count);
	if (m_progress5)
		m_progress5->SetRange(0, count);
	if (m_progress6)
		m_progress6->SetRange(0, count);
	if (m_progress7)
		m_progress7->SetRange(0, count);
	if (m_progress8)
		m_progress8->SetRange(0, count);

	if (m_progress1)
		m_progress1->SetPos(0);


//	if (m_bEnableA1)
//	{
//		if (m_progress2)
//			m_progress2->SetPos(0);
//
//		for (int i = 0; i < (count - 1); i++)	//Dates
//		{
//			if (m_progress3)
//				m_progress3->SetPos(0);
//
//			for (int k = 1; k < count; k++)	//TeamA Offset
//			{
//				if (m_progress4)
//					m_progress4->SetPos(0);
//
//				for (int j = 0; j < count; j++)	//TeamA Start
//				{
//					if (errchk = CalcDate(i, count, j, k, false, false))
//						break;
//
//					if (m_progress4)
//						m_progress4->SetPos(j+1);
//				}
//
//				if (errchk)
//					break;
//
//				if (m_progress3)
//					m_progress3->SetPos(k);
//			}
//
//			if (!errchk)
//				break;
//
//			if (m_progress2)
//				m_progress2->SetPos(i+1);
//
//			/*for (int p = 0; p < m_teams.GetCount(); p++)
//				m_teams.GetAt(p).DumpTeam((CString)(char)('A'+p));
//
//			MessageBox(NULL, (CString)"Done " + ConvertIntToString(i+1), "Debug", MB_OK);*/
//		}
//
//		if (m_progress1)
//			m_progress1->SetPos(m_progress1->GetPos()+1);
//	}

	if (m_bEnableA1)
	{
		CUIntArray a, b;

		int possible = GeneratePossibleMatches(count, a, b);

		//Do Something with the pre created matches
	}

	if (m_bEnableA2)
	{
		if (!errchk)
		{
			ClearDates();

			if (m_progress2)
				m_progress2->SetPos(0);

			for (int i = 0; i < (count - 1); i++)	//Dates
			{
				if (m_progress3)
					m_progress3->SetPos(0);

				for (int k = 1; k < count; k++)	//TeamA Offset
				{
					if (m_progress4)
						m_progress4->SetPos(0);

					for (int j = 0; j < count; j++)	//TeamA Start
					{
						if (errchk = CalcDate(i, count, j, k, true, false))
							break;

						if (m_progress4)
							m_progress4->SetPos(j+1);
					}

					if (errchk)
						break;

					if (m_progress3)
						m_progress3->SetPos(k);
				}

				if (m_progress2)
					m_progress2->SetPos(i+1);

				if (i == count-2)
					if (m_progress1)
						m_progress1->SetPos(m_progress1->GetPos()+1);

				if (!errchk)
					break;
			}
		}
	}

	if (m_bEnableA3)
	{
		if (!errchk)
		{
			ClearDates();

			if (m_progress2)
				m_progress2->SetPos(0);

			for (int i = 0; i < (count - 1); i++)	//Dates
			{
				if (m_progress3)
					m_progress3->SetPos(0);

				for (int k = 1; k < count; k++)	//TeamA Offset
				{
					if (m_progress4)
						m_progress4->SetPos(0);

					for (int j = 0; j < count; j++)	//TeamA Start
					{
						if (errchk = CalcDate(i, count, j, k, false, true))
							break;

						if (m_progress4)
							m_progress4->SetPos(j+1);
					}

					if (errchk)
						break;

					if (m_progress3)
						m_progress3->SetPos(k);
				}

				if (m_progress2)
					m_progress2->SetPos(i+1);

				if (i == count-2)
					if (m_progress1)
						m_progress1->SetPos(m_progress1->GetPos()+1);
			}
		}
	}

	//if (m_bEnableRG)
	//{
	//	if (!errchk)
	//	{
	//		srand((unsigned)time(NULL));

	//		CUIntArray Ta, Tb, Tp;

	//		ClearDates();

	//		int possible = GetPossibleMatches(count);

	//		if (m_progress2)
	//			m_progress2->SetPos(0);

	//		for (int i = 0; i < count-1; i++)
	//		{
	//			int a, b;
	//			
	//			Ta.RemoveAll();
	//			Tb.RemoveAll();
	//			Tp.RemoveAll();

	//			while (true)
	//			{
	//				if (Ta.GetCount() == possible)	//Find other ordering
	//				{
	//					ClearDates();
	//					i = -1;
	//					//MessageBox(NULL, "Resetting", "Debug", MB_OK);
	//					break;
	//				}

	//				while (AreInParallelListsI(a = rand()%count, b = rand()%count, Ta, Tb) || (a == b) /*|| IsInArray(a, Tp) || IsInArray(b, Tp)*/)
	//					;
	//				
	//				Ta.Add(a);
	//				Tb.Add(b);

	//				//MessageBox(NULL, ConvertIntToString(Ta.GetCount()), "Debug", MB_OK);

	//				//DumpLists(Ta, Tb);

	//				if (CheckAddMatch(a, b, i))
	//				{
	//					Tp.Add(a);
	//					Tp.Add(b);

	//					if (Tp.GetCount() == count)
	//					{
	//						//MessageBox(NULL, ConvertIntToString(i), "Date", MB_OK);
	//						break;
	//					}
	//				}
	//			}

	//			if (m_progress2)
	//				m_progress2->SetPos(m_progress2->GetPos()+1);

	//			if (i == -1)
	//				m_progress2->SetPos(0);
	//		}

	//		if (m_progress1)
	//			m_progress1->SetPos(m_progress1->GetPos()+1);

	//		errchk = true;
	//	}
	//}

	if (m_bEnableRG)
	{
		if (!errchk)
		{
			srand((unsigned)time(NULL));

			CUIntArray a, b, p, e;

			int possible = GeneratePossibleMatches(count, a, b);

			int r, repeated = 0;

			if (m_progress2)
				m_progress2->SetPos(0);

			for (int i = 0; i < (count - 1); i++)	//Dates
			{
				p.RemoveAll();
				e.RemoveAll();

				for (int j = 0; j < (count/2); j++)
				{
					if (e.GetCount() + p.GetCount() == possible)
					{
						if (repeated > (count*count))
						{
							repeated = 0;
							ClearDates();
							i = -1;
							break;
						}
						else
						{
							ClearDate(i);
							i--;
							repeated++;
							break;
						}
					}

					while (IsInArray(r = (rand()%possible), p) || IsInArray(r, e));
						;

					if (CheckAddMatch(a.GetAt(r), b.GetAt(r), i))
						p.Add(r);
					else
					{
						e.Add(r);
						j--;
					}
				}

				if (m_progress2)
					if (i == -1)
						m_progress2->SetPos(0);
					else
						m_progress2->SetPos(i+1);
			}

			errchk = true;

			if (m_progress1)
				m_progress1->SetPos(m_progress1->GetPos()+1);
		}
	}

	CFile fileF("C:\\Finished.chk", CFile::modeCreate);
	fileF.Close();

	if (!errchk)
		return false;

	return true;
}

CString ConvertIntToString(int inttoconvert)
{
	char valconv[99];
	_itoa(inttoconvert, valconv, 10);
	return valconv;
}

/*void CFixture::Dump()	//For Debug Purposes
{
	CString finaldump = "";

	int count = m_teams.GetCount();

	for (int i = 0; i < (count - 1); i++)
	{
		finaldump += "Fecha " + ConvertIntToString(i+1) + ":\n";

		for (int j = 0; j < count; j++)
			finaldump += ((CString)(char)('A'+j)) + " vs " + ((CString)(char)('A'+m_teams.GetAt(j).m_dates.GetAt(i))) + (j != count-1?" - ":"");

		finaldump += "\n\n";
	}

	MessageBox(NULL, finaldump, "Fixture", MB_OK);
}*/

CString CFixture::DumpToString()
{
	CString finaldump = "";

	int count = m_teams.GetCount();

	for (int i = 0; i < (count - 1); i++)
	{
		finaldump += "Fecha " + ConvertIntToString(i+1) + ":\r\n";

		int tmp;
		CUIntArray forbid;

		for (int j = 0; j < count; j++)
		{
			tmp = m_teams.GetAt(j).m_dates.GetAt(i);

			if (!IsInArray(j, forbid))
			{
				if (m_teams.GetAt(tmp).m_bNotPlay)
					finaldump += (j != 0?" - ":"") + m_teams.GetAt(j).m_name + " no juega";
				else
					finaldump += (j != 0?" - ":"") + m_teams.GetAt(j).m_name + " vs " + m_teams.GetAt(tmp).m_name;

				forbid.Add(tmp);
			}
		}

		if (i != (count - 2))
			finaldump += "\r\n\r\n";
	}

	return finaldump;
}

bool CTeam::WasPlayed(int teamindex)
{
	int count = m_dates.GetCount();

	for (int i = 0; i < count; i++)
		if (m_dates.GetAt(i) == teamindex)
			return true;

	return false;
}

bool CFixture::IsPlaying(int date, int teamindex)
{
	int count = m_teams.GetCount();

	for (int i = 0; i < count; i++)
		if (((m_teams.GetAt(i).m_dates.GetCount()-1) >= date) && (m_teams.GetAt(i).m_dates.GetAt(date) == teamindex))
			return true;

	return false;
}
