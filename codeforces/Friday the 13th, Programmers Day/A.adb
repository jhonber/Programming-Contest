-- http://codeforces.com/contest/345/problem/A

with Ada.Text_IO, Ada.Float_Text_IO, Ada.Integer_Text_IO;
use Ada;
use Ada.Text_IO;
procedure A is
	package T_IO renames Ada.Text_IO;
	S:	String (1..50);
	len: Natural;
	P:		Float;
	Ans: Float := 0.0;

begin
--	Get_line(Line,P);
	get_line(S, len);
--	S := S(1,len);
	Ada.Float_Text_IO.get (Item =>P);
--	Float_Text_IO.Get (Real);
--	Float_Text_IO.Put (P, Aft=>5);
--	Text_IO.New_Line;
--	put_line (S(1..len));
--	Text_IO.New_Line;
	
	for i in 1 .. len loop
		if(S(i) = '1') then
			Ans := Ans + 1.0;
		end if;
		if(S(i) = '?') then
			Ans := Ans + P;
		end if;
	end loop;

	Ans := Ans / Float(len);
	Float_Text_IO.Put (ans, Aft=>5, Exp=>0);
	
end A;

