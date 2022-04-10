#include <iostream>
#include <vector>
#include <queue>

struct Pair {
	int start;
	int end;
	Pair(int start, int end) : start(start), end(end) {}
};

struct compbystart {
	bool operator() (Pair a, Pair b) {
		if (a.start == b.start) {
			return a.end > b.end;
		}
		else {
			return a.start > b.start;
		}
	}
};

struct compbyend {
	bool operator() (Pair a, Pair b) {
		if (a.end == b.end) {
			return a.start > b.start;
		}
		else {
			return a.end > b.end;
		}
	}
};

std::priority_queue<Pair, std::vector<Pair>, compbystart> tables;
std::priority_queue<Pair, std::vector<Pair>, compbyend> rooms;

int main()
{
	int num, start, end;
	std::cin >> num;
	for (int i = 0; i < num; ++i) {
		std::cin >> start >> end;
		tables.push((Pair(start, end)));
	}
	rooms.push(Pair(0, 0));

	for (int i = 0; i < num; ++i) {
		Pair table = tables.top();
		tables.pop();
		Pair room = rooms.top();
		rooms.pop();
		if (room.end <= table.start) {
			room.end = table.end;
			rooms.push(room);
		}
		else {
			rooms.push(room);
			rooms.push(Pair(table.start, table.end));
		}
	}
	std::cout << rooms.size();
}
