
#include <afxtempl.h>

int OverAdd(int num, int offset, int max);
int OverSubtract(int num, int offset, int max);
bool IsInArray(int num, CUIntArray& disallowed);
int SecureOverAdd(int num, int offset, int max, CUIntArray& disallowed);
int SecureOverSubtract(int num, int offset, int max, CUIntArray& disallowed);
CString ConvertIntToString(int inttoconvert);
int Reduce(int numtr, int maxnumNI);
bool AreInParallelLists(int numA, int numB, CUIntArray& listA, CUIntArray& listB);
bool AreInParallelListsI(int numA, int numB, CUIntArray& listA, CUIntArray& listB);
int GetPossibleMatches(int num);
void DumpLists(CUIntArray& a, CUIntArray& b);
int GeneratePossibleMatches(int count, CUIntArray& a, CUIntArray& b);

class CTeam
{
public:
	CTeam() {m_name = ""; m_bNotPlay = false;}
	void operator=(const CTeam& b) {m_name = b.m_name; m_bNotPlay = b.m_bNotPlay; m_dates.Copy(b.m_dates);}
	CTeam(CString name, bool notplay = false) {m_name = name; m_bNotPlay = notplay;}
	CTeam(CTeam& b) {operator=(b);}

	bool m_bNotPlay;

	CString m_name;
	CUIntArray m_dates;

	bool WasPlayed(int teamindex);
	void DumpTeam(CString name);
};

class CFixture
{
public:
	CFixture() {m_progress1 = m_progress2 = m_progress3 = m_progress4 = m_progress5 = m_progress6 = m_progress7 = m_progress8 = NULL; m_bEnableA1 = true; m_bEnableA2 = true; m_bEnableA3 = true;}

	CProgressCtrl* m_progress1;
	CProgressCtrl* m_progress2;
	CProgressCtrl* m_progress3;
	CProgressCtrl* m_progress4;
	CProgressCtrl* m_progress5;
	CProgressCtrl* m_progress6;
	CProgressCtrl* m_progress7;
	CProgressCtrl* m_progress8;

	bool m_bEnableA1;
	bool m_bEnableA2;
	bool m_bEnableA3;
	bool m_bEnableRG;

	CArray<CTeam> m_teams;

	void CheckConsistency(int date, int start, int offset, int a, int b, int c, bool secure);

	bool IsPlaying(int date, int teamindex);

	bool CheckDates();
	void ClearDate(int date);
	bool CheckAddMatch(int teamA, int teamB, int date);
	bool CalcTeam(int date, int teamA, int count, int start, int offset, bool secure);
	bool CalcDate(int date, int count, int start, int offset, bool secure, bool carry);

	void DumpTeamDates(CString caption, bool filedump = false);

	void ClearDates();
	bool Calculate();

	CString DumpToString();
};