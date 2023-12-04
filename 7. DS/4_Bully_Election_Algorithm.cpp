
/*
Bully Algo: 
Process with higher priority get msg from process with lower priority. Higher priority acknowledge the lower priority 
process after becoming coordinator.
The most higher priority process can only become the coordinator process.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class BullyAlgorithm
{
	public:
		BullyAlgorithm(int id, std::vector<int> &processIds): id_(id), processIds_(processIds), coordinator_(id) {}
		void startElection()
		{
			cout << "\nProcess 0 {" << id_ << "} initiates an election."<<endl;
			
			bool higherPriorityExists = false;
			std::map<int, bool> responses;
			
			for (int i = 0; i < processIds_.size(); ++i)
			{
				if (processIds_[i] > id_)
				{
					cout << "\nProcess 1 {" << id_ << "} sends 'Election' message to Process " << i + 1 << "{" << processIds_[i] << "}" <<endl;
					sendMessage(i, "Election");
					responses[i] = false;
				}
			}
			
			for (int i = 0; i < processIds_.size(); ++i)
			{
				if (processIds_[i] > id_)
				{
					if (receivedOk(i))
					{
						cout << "Process 1 {" << id_ << "} received 'Ok' from Process " << i + 1 << "{" << processIds_[i] << "}" <<endl;
						responses[i] = true;
						higherPriorityExists = true;
					}
				}
			}
			
			if (!higherPriorityExists)
			{
				cout << "\nProcess 1 {" << id_ << "} becomes the coordinator." <<endl;
				for (int i = 0; i < processIds_.size(); ++i)
				{
					if (i != id_)
					{
						cout << "\nProcess " << id_ << " sends 'Coordinator' message to Process " << i + 1 <<endl;
						sendMessage(i, "Coordinator");
					}
				}
			}
			
			else
			{
				bool coordinatorElected = false;
				for (int i = processIds_.size()-1; i > 0;--i)
				{
					if (responses[i])
					{
						if (receivedCoordinator(processIds_[i]))
						{
							coordinatorElected = true;
							coordinator_ = i + 1;
							cout << "\nProcess 1 acknowledges Process "<< i + 1 << "{" << processIds_[i] << "}"<< " as the coordinator." <<endl;
							for (int i = 0; i < processIds_.size(); ++i)
							{
							 if (i + 1 != coordinator_)
							 {
								cout << "\nProcess " << coordinator_<< " sends 'Coordinator' message to Process " << i + 1 << endl;
								sendMessage(i, "Coordinator");
							 }
							}
							break;
						}
					}
				}
				
				if (!coordinatorElected)
				{
					cout << "Process 1 {" << id_ << "} assumes it has the highest priority and becomes the coordinator." << endl;
					for (int i = 0; i < processIds_.size(); ++i)
					{
						if (i != id_)
						{
							cout << "\nProcess " << id_ << " sends 'Coordinator' message to Process " << i + 1 << endl;
							sendMessage(i, "Coordinator");
						}
					}
				}
			}
		}
		
		void sendMessage(int receiverId, const std::string &message)
		{
		}
		
		bool receivedOk(int senderId)
		{
			return true;
		}
		
		bool receivedCoordinator(int senderId)
		{
			int max = *max_element(processIds_.begin(), processIds_.end());
			if (max == senderId)
				return true;
			return false;
		}
		
		int getCoordinator() const
		{
			return coordinator_;
		}
		
		private:
		int id_;
		std::vector<int> &processIds_;
		int coordinator_;
		
};


int main()
{
	int n;
	cout << "\nEnter the number of processes: ";
	cin >> n;
	
	std::vector<int> processIds;
	 
	cout<< "\nEnter the priorities" <<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter priority of process {" << i + 1 << "}: ";
		int priority;
		cin >> priority;
		processIds.push_back(priority);
	}
	
	int initiatingProcessId = processIds[0];
	BullyAlgorithm initiatingProcess(initiatingProcessId, processIds);
	
	cout << "\nStarting Bully Algorithm Election..." << endl;
	initiatingProcess.startElection();
	
	// Conclude by displaying the elected coordinator
	cout << "\nElected Coordinator: Process " <<initiatingProcess.getCoordinator() << endl;
	return 0;
}
