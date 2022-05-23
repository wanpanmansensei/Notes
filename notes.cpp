// add edit line eg.(e.3)
// changed line 971 and 888
#include "fac.h"
#include <vector>

char const *bck = "../../../../.notesbackup/.notes_backup.dat";
char const *nf = "note.txt";
char const *nf2 = "notetemp.txt";

   // for secret notes
char const *bcp = "../../../../.notesbackup/.sbckp.dat";
char const *bcpp = "../../../../.notesbackup/.sbckpp.dat";

char const *ns = ".snote.dat";
char const *ps = ".spswd.dat";
char const *ps2 = ".sptemp.dat";
char const *ns2 = "stemp.txt";
char const *ns4 = ".stemp3.txt";

char const *bin = ".bin.txt";
   /* 
      char const *bck = "a"; // "../../../../.notesbackup/.notes_backup.dat";
      char const *nf = "b"; // "note.txt"; // fac/note.txt works too char
      const *nf2 = "c"; // "notetemp.txt";

      // for secret notes char const *bcp = "d"; //
      "../../../../.notesbackup/.sbckp.dat"; char const *bcpp = "e"; //
      "../../../../.notesbackup/.sbckpp.dat";

      char const *ns = "f"; // ".snote.dat"; char const *ps = "g"; //
      ".spswd.dat"; char const *ps2 = "h"; // ".sptemp.dat"; char const *ns2 = 
      "i"; // "stemp.txt"; char const *ns4 = "j"; // ".stemp3.txt"; */

// values
char hig = '*';
char dis = '#';

// func
void help();
void del();
void creator();
void sec();
void notes();

// sec func
void schp();
void sdel();
void scpswd();
void spswd();
void encrypt();
void decrypt();
int valid();
void secup();

int key = 10;

void secup()
{

	clrscr();
	cout << grey << "  SECTET NOTE | Enter 'exit' to exit\n";
	cout <<
		"——————————————————————————————————————\n"
		<< res;
}

void rem()
{
	cout << '\b';
	cout << ' ';
	cout << '\b';
}

void encrypt(const char *n1, const char *n2)
{

	ifstream fps;
	ofstream fpt;
	fps.open(n1);
	if (!fps)
		return;
	fpt.open(n2);
	if (!fps)
		return;
	srand(key);
	string str;
	while (!fps.eof())
	{
		getline(fps, str);
		if (!str.empty())
		{
			for (int i = 0; i < str.size(); i++)
			{
				int m = 1 + rand() % 99;
				str[i] = str[i] + m;
			}
			fpt << str << '\n';
		}
	}
	fps.close();
	fpt.close();
	std::rename(n2, n1);
}

void decrypt(const char *n1, const char *n2)
{
	ifstream fps;
	ofstream fpt;
	fps.open(n1);
	if (!fps)
		return;
	fpt.open(n2);
	if (!fps)
		return;
	srand(key);
	string str;
	while (!fps.eof())
	{
		getline(fps, str);
		if (!str.empty())
		{
			for (int i = 0; i < str.size(); i++)
			{
				int m = 1 + rand() % 99;
				str[i] = str[i] - m;
			}
			fpt << str << '\n';
		}
	}
	fps.close();
	fpt.close();
	std::rename(n2, n1);
}

void restore(char const *f, char const *ck)
{
	ifstream ifs;
	ofstream ofs;
	ifs.open(ck);
	if (!ifs)
	{
		ifs.close();
		cout << "No backup found!\n";
		ofs.open(f);
		ofs.close();
		return;
	}
	ofs.open(f);
	if (!ofs)
	{
		cout << "some error!\n";
		ofs.close();
		return;
	}
	char ch;
	vector < string > vec;
	string str;
	while (getline(ifs, str))
	{
		vec.push_back(str);
	}

  for (string st:vec)
		if (!st.empty())
			ofs << st << '\n';
	ofs.close();
	ifs.close();
	cout << "Restored Successfully!\n";
	cout << Coff;
}

void backup(string f, string ck)
{
	ifstream ifs;
	ofstream ofs;
	ifs.open(f);
	if (!ifs)
	{
		cout << "\n\t         Error!";
		ifs.close();
		return;
	}
	ofs.open(ck);
	char ch;
	vector < string > vec;
	string str;
	while (getline(ifs, str))
	{
		vec.push_back(str);
	}

  for (string st:vec)
		ofs << st << '\n';
	ofs.close();
	ifs.close();
	cout << "\n\t         Done!";
}

int valid(string st)
{
	int val = 0;
	int num = 0;
	int d = 0;
	int m = 0;
	int y = 0;
	int i = 0;

  for (char c:st)
	{
		if (isdigit(c))
		{
			num = (num * 10) + (c - '0');
		}
		else
		{
			i++;
			if (i == 1)
				d = num;
			else if (i == 2)
				m = num;
			else if (i == 3)
				y = num;
			else
				return val;
			num = 0;
		}
	}
	if (d == 0)
		d = num;
	else if (d != 0 && m == 0)
		m = num;
	else
		y = num;

	if (d > 0 && d <= 31)
		val++;
	if (m > 0 && m <= 12)
		val++;
	if (y > 0)
		val++;

	return val;
}

void help()
{
	clrscr();
	cout << white << "\t\tEnter-\n\n" << res;
	cout << "help - for instructions\n";
	cout << "chp - change password\n";
	cout << "del - delete lines separated by char\n";
	cout << "creator - know the creator\n";
	cout << "exit/ex - exit the secret note\n";
	cout << "backup - backup the notes\n\n";
	cout << "put '^'before a line to merge\n...it with prev. line\n";
	cout << "put '*' before/after a line\n...to highlight\n";
	cout << grey << "\nPress any key to continue..." << res;
	getch();
	clrscr();
}

	// sec executions
void schp()
{
	string c, p;
	bool spas = false;
	cout << "Enter old sec password :";

	decrypt(ps, ps2);
	ifstream ifs(ps);
	getline(ifs, p);
	ifs.close();
	encrypt(ps, ps2);

	while (1)
	{
		char ch = getch();
		if (ch == 10)
			break;
		else if (ch == 127)
		{
			if (c.size() > 0)
			{
				c.pop_back();
				rem();
			}
		}

		else
		{
			c.push_back(ch);
			cout << '*';
		}

		if (c == p)
		{
			spas = true;
			break;
		}
		else
		{
			spas = false;
		}

	}
	if (spas)
	{
		cout << "\nEnter new sec password :";
		spswd();
	}
	else
	{
		cout << "\nWrong password\n\n";
		usleep(800000);
	}
	spas = false;
	clrscr();
}

void sdel()
{
	ifstream isn;
	ofstream osn;

	string sn;
	char ch;
	cout << "Enter line to delete :";
	cin >> sn;

	vector < int >svect;
	stringstream ss(sn);
	for (int i; ss >> i;)
	{
		svect.push_back(i);
		if (ss.peek() != isdigit(i))
			ss.ignore();
	}

	std::sort(svect.begin(), svect.end());

	vector < string > svec;
	string str;

	decrypt(ns, ns4);
	isn.open(ns);
	osn.open(ns2, ofstream::out);

	while (getline(isn, str))
	{
		svec.push_back(str);
	}

  for (int j:svect)
	{
		if (j <= svec.size() && j != 0)
			svec[j - 1].erase();
	}
  for (string st:svec)
	{
		if (!st.empty())
			osn << st << '\n';
	}
	osn.close();
	isn.close();
	rename(ns2, ns);
	cout << Coff;

	encrypt(ns, ns4);
}

void scpswd()					// check password
{
	bool spas = false;
	bool enp = false;
	string str;
	ifstream isp(ps);
	if (!isp)
	{
		isp.close();
		sec();
	}
	else
	{
		getline(isp, str);
		isp.close();
		if (!str.empty())
		{
		  for (char ch:str)
			{
				if (!isalnum(ch))
					if (!ispunct(ch))
						enp = true;
			}
		}
		else
			sec();
	}

	string c;
	string p;

	if (enp)
		decrypt(ps, ps2);
	isp.open(ps);
	getline(isp, p);
	isp.close();
	encrypt(ps, ps2);

	cout << "Enter sec password :";
	while (1)
	{
		char ch = getch();
		if (ch == 10)
			break;
		else if (ch == 127)
		{
			if (c.size() > 0)
			{
				c.pop_back();
				rem();
			}
		}
		else
		{
			c.push_back(ch);
			cout << '*';
		}

		if (c == p)
		{
			spas = true;
			break;
		}
		else
		{
			spas = false;
		}

	}
	if (spas)
		sec();
	else
	{
		cout << "\nWrong password !\n";
		usleep(800000);
		clrscr();
	}
}

void spswd()					// new password
{
	string p;
	while (1)
	{
		char ch = getch();
		if (ch == 10)
			break;
		else if (ch == 127)
		{
			if (p.size() > 0)
			{
				p.pop_back();
				cout << '\b';
				cout << ' ';
				cout << '\b';
			}
		}
		else
		{
			p.push_back(ch);
			cout << '*';
		}
	}
	secup();
	if (p.size() != 0)
	{
		ofstream ofp(ps);
		ofp << p;
		ofp.close();
		cout << "\nNew password saved Successfully\n";
		encrypt(ps, ps2);
		usleep(1000000);
		clrscr();
	}
	else
	{
		cout << Coff;
		cout << "\n\nPassword can't be empty!\n";
		usleep(1000000);
		clrscr();
		cout << Con;
		sec();
	}
}

	// executions

void del()
{
	ifstream ifn(nf);
	ofstream ofn(nf2, ofstream::out);
	string nn;
	char ch;
	cout << "Enter line(s) to delete :";
	cin >> nn;
	vector < int >vect;
	stringstream ss(nn);
	for (int i; ss >> i;)
	{
		vect.push_back(i);
		if (ss.peek() != isdigit(i))
			ss.ignore();
	}

	std::sort(vect.begin(), vect.end());
	vector < string > vec;
	string str;

	while (getline(ifn, str))
	{
		vec.push_back(str);
	}

  for (int j:vect)
	{
		if (j <= vec.size() && j != 0)
			vec[j - 1].erase();
	}
  for (string st:vec)
	{
		if (!st.empty())
			ofn << st << '\n';
	}
	ofn.close();
	ifn.close();
	rename(nf2, nf);
	cout << Coff;
}

void creator()
{
	clrscr();
	cout << "Created by Saitama\n";
	cout << "\n\n\npress any key to continue...";
	getch();
	clrscr();
}

bool isenc(string file)
{
	int lim = 1, rep = 5;
	ifstream ifs(file);
	string strr;
	while (!ifs.eof())
	{
		getline(ifs, strr);
		if (!strr.empty())
		{
		  for (char chh:strr)
			{
				if ((int)chh >= 128)
					lim--;
			}
			rep--;
		}
		if (lim <= 0)
		{
			return true;
		}
		else if (rep <= 0)
		{
			return false;
		}
	}

}

string secfunc(string line2)
{

	bool cancel = false;
	string din;
	string line = line2 + " ";
	while (1)
	{
		cout << grey << "Enter Date: " << res;
		char ch;
		string p = "";
		while (1)
		{
			ch = getch();
			if (ch == 10)
				break;
			else if (ch == 127)
			{
				if (p.size() > 0)
				{
					p.pop_back();
					rem();
				}
			}
			else
			{
				if (!isdigit(ch))
					if (p.size() > 0)
						ch = '-';
				p.push_back(ch);
				cout << ch;
			}
		}
		din = p;
		std::time_t t = std::time(0);	// get time now
		std::tm * now = std::localtime(&t);
		if (din.size() == 0)
		{
			line =
				line + "[" + std::to_string(now->tm_mday) + '-' +
				to_string(now->tm_mon + 1) + '-' + to_string(now->tm_year + 1900) + "]";
			break;
		}
		else if (valid(din) == 1)
		{
			line = line + "[" + din + '-' +
				to_string(now->tm_mon + 1) + '-' + to_string(now->tm_year + 1900) + "]";
			break;
		}
		else if (valid(din) == 2)
		{
			line = line + "[" + din + '-' + to_string(now->tm_year + 1900) + "]";
			break;
		}
		else if (valid(din) == 3)
		{
			line = line + "[" + din + "]";
			break;
		}
		else
		{
			if (din.size() == 1 && isalpha(din[0]))
			{
				if (din[0] == 'c')
				{
					cancel = true;
					break;
				}
				else
					break;
			}
			else
			{
				cout << "\ninvalid date format!\n";
				getch();
			}
		}
	}
	if (!cancel)
	{
		char ch1;
		cout << grey << "\n1.fin 2.disc 3.wat: " << res;
		while (1)
		{
			ch1 = getch();
			if (ch1 == '1' || ch1 == 'f')
			{
				line = line + '*';
				cout << "finished";
				break;
			}
			else if (ch1 == '2' || ch1 == 'd')
			{
				line.insert(0, "#");
				cout << "discontinued";
				break;
			}
			else if (ch1 == '3' || ch1 == 'w')
			{
				line.insert(0, "*");
				cout << "waiting";
				break;
			}
			else if (ch1 == 10)
			{
				cout << "N/A";
				break;
			}
		}
		if (ch1 != 10)
		{
			cout << "\n";
			char pro = ' ';
			string val = "";
			string val2 = "";
			string nam = "";
			if (line[line.size() - 1] == '*')	// fin
			{
				pro = 'f';
				cout << grey << "seasons watched :" << res;

			}
			else if (line[0] == '#')	// desc
			{
				pro = 'd';
				cout << grey << "Episodes watched :" << res;

			}
			else if (line[0] == '*')	// wat
			{
				pro = 'w';
				cout << grey << "seasons watched :" << res;

			}


			string p = "";
			bool plsd = false;
			while (1)
			{
				char ch = getch();
				if (ch == 10)
					break;
				else if (ch == 127)
				{
					if (p.size() > 0)
					{
						p.pop_back();
						rem();
					}
				}
				else
				{
					if (isdigit(ch))
					{
						p.push_back(ch);
						cout << ch;
					}
					else if (pro == 'd')
					{
						if (plsd == false && ch == '+')
						{
							plsd = true;
							p.push_back(ch);
							cout << ch;
						}
					}
				}
			}
			bool pls = false;

		  for (char c:p)
			{
				if (!isdigit(c))
					pls = true;
				if (isdigit(c) && pls == false)
				{
					val.push_back(c);
				}
				else if (isdigit(c) && pls == true)
					val2.push_back(c);
			}

			if (pro == 'f' || pro == 'w')
				nam = "sn " + val;
			else if (pro == 'd')
			{
				if (!pls)
					nam = "ep " + val;
				else
					nam = "sn " + val + " , ep " + val2;
			}
			if (p.size() > 0)
				line.replace(line.find_last_of("["), 1, "(" + nam + ")" + " [");
		}
	}
	return line;
}

void sec()
{
	bool enc = true;
	ifstream ifs(ns);
	if (!ifs)
	{
		ifs.close();
		clrscr();
		restore(ps, bcpp);
		usleep(300000);
		clrscr();
		cout << '\n';
		restore(ns, bcp);
		usleep(300000);
		clrscr();
		scpswd();
		return;
	}
	decrypt(ps, ps2);
	string mt;
	ifstream isp(ps);
	getline(isp, mt);
	isp.close();
	encrypt(ps, ps2);
	if (mt.size() == 0)
	{
		secup();
		cout << "\nEnter a new sec password :";
		spswd();
	}
	// string line;
	string line1;
	string line2;
	int j, k;
	char show = '0';
	int sh = 0;
	while (1)
	{
		secup();
		if (enc)
		{
			decrypt(ns, ns4);
			enc = false;
		}
		j = 1;
		k = 0;
		string sgap;
		ofstream osn;
		ifstream isn(ns);
		if (!isn)
		{
			isn.close();
			ofstream ofs(ns);
			ofs.close();
			cout << "\nfile not found,so created!\n";
			usleep(1000000);
		}
		while (getline(isn, line1))
		{
			sgap = (j < 10) ? " " : "";
			if (j > k)
			{
				cout << res << sgap << j << ".";
				k = j;
			}
			if (line1[0] == hig)
			{
				line1.erase(0, 1);
				cout << green;
				sh = 1;
			}
			else if (line1[0] == dis)
			{
				line1.erase(0, 1);
				cout << grey;
				sh = 4;
			}
			else if (line1[line1.size() - 1] == hig)
			{
				line1.erase(line1.size() - 1, line1.size());
				cout << yel;
				sh = 2;
			}
			else
				sh = 3;

			if (show == '0')
			{
				cout << line1 << res << '\n';
				j++;
			}
			else if (show == '1' && sh == 1)
			{
				cout << line1 << res << '\n';
				j++;
			}
			else if (show == '2' && sh == 2)
			{
				cout << line1 << res << '\n';
				j++;
			}
			else if (show == '3' && sh == 3)
			{
				cout << line1 << res << '\n';
				j++;
			}
			else if (show == '4' && sh == 4)
			{
				cout << line1 << res << '\n';
				j++;
			}
			else if (show == '5' && sh != 4)
			{
				cout << line1 << res << '\n';
				j++;
			}
			else
				cout << res;
		}
		isn.close();
		if (!enc)
		{
			encrypt(ns, ns4);
			enc = true;
		}
		else
		{
			cout << "errororoorr!";
			getch();
		}

		cout << Con;
		sgap = (j < 10) ? " " : "";
		if (j > k)
			cout << res << sgap << j << ".";
		getline(cin, line2);
		if (line2 == "chp")
		{
			schp();
		}
		else if (line2 == "del")
		{
			if (show == '0')
				sdel();
			else
			{
				cout << "access denied\n";
				usleep(500000);
			}
		}
		else if (line2 == "exit" || line2 == "ex")
		{
			cout << Coff;
			clrscr();
			return;
		}
		else if (line2 == "backup")
		{
			cout << Coff;
			backup(ns, bcp);
			usleep(300000);
			backup(ps, bcpp);
			usleep(300000);
		}
		// ////////////
		else if (line2 == "decrypt")
		{
			decrypt(ns, ns4);
			getch();
			encrypt(ns, ns4);
		}
		// ///////////
		// else if (line2 == ".a" || line2 == ".b" || line2 == ".c" || line2
		// == ".d" || line2 == ".e")
		else if (line2.size() == 2 && (line2[0] == '.' && isalpha(line2[1])))
		{
			if (line2 == ".a")
			{
				show = '1';
			}
			else if (line2 == ".b")
			{
				show = '2';
			}
			else if (line2 == ".c")
			{
				show = '3';
			}
			else if (line2 == ".d" || ".all")
			{
				show = '0';
			}
			else if (line2 == ".e")
			{
				show = '4';
			}
			else if (line2 == ".f")
			{
				show = '5';
			}

		}
		else if (!line2.empty())
		{
			string line = secfunc(line2);

			if (enc)
			{
				decrypt(ns, ns4);
				enc = false;
			}
			osn.open(ns, ios::app);
			osn << line << '\n';
			osn.close();
		}
	}
}

void notes()
{
	string line1;
	string line2;
	int i;
	while (1)
	{
		i = 1;
		clrscr();
		// reading part
		cout << Coff;
		ifstream ifn(nf);
		if (!ifn)
		{
			help();
			ifn.close();
			restore(nf, bck);
			usleep(500000);
			ifstream ifs(ns);
			if (!ifs)
			{
				ifs.close();
				clrscr();
				restore(ps, bcpp);
				usleep(500000);
				clrscr();
				restore(ns, bcp);
				usleep(500000);
			}
			else
				ifs.close();
			clrscr();
			ifn.open(nf);
		}
		string gap;
		while (getline(ifn, line1))
		{
			gap = (i < 10) ? " " : "";
			cout << gap << i << ".";
			if (line1[0] == hig)
			{
				line1.erase(0, 1);
				cout << green;
			}
			else if (line1[0] == dis)
			{
				line1.erase(0, 1);
				cout << grey;
			}
			else if (line1[line1.size() - 1] == hig)
			{
				line1.erase(line1.size() - 1, line1.size());
				cout << yel;
			}

			cout << line1 << '\n';
			i++;
			cout << res;
		}
		ifn.close();
		// writing part
		string gap2;
		gap2 = (i < 10) ? " " : "";
		cout << gap2 << i << ".";
		cout << Con;
		getline(cin, line2);
		if (line2 == "help")
		{
			cout << Coff;
			help();
		}
		else if (line2 == "creator")
		{
			cout << Coff;
			creator();
		}
		else if (line2 == "del")
		{
			del();
		}
		else if (line2 == "backup")
		{
			cout << Coff;
			backup(nf, bck);
			usleep(500000);
		}
		else if (line2 == "sec")
		{
			scpswd();
		}
		else if (line2 == "s.backup")
		{

			cout << Coff;
			backup(ns, bcp);
			usleep(300000);
			backup(ps, bcpp);
			usleep(300000);
		}
		else
		{
			if (!line2.empty())
			{

				if (line2[0] == 's' && line2[1] == '.')
				{
					line2.erase(0, 2);

					string line = secfunc(line2);

					decrypt(ns, ns4);
					ofstream osn(ns, ios::app);
					osn << line << '\n';
					osn.close();
					encrypt(ns, ns4);
				}
				else
				{
					ofstream ofn(nf, ios::app);
					if (!ofn)
					{
						cout << "problem writing in file\n";
						getch();
						break;
					}
					ofn << line2 << '\n';
					ofn.close();
				}
			}
		}
	}
}

int main()
{
	cout << unitbuf;
	cout << Coff;
	ifstream ifs(ns);
	if (!ifs)
	{
		ifs.close();
	}
	else
	{
		ifs.close();
		if (!isenc(ns))
			encrypt(ns, ns4);
	}

	notes();
}
