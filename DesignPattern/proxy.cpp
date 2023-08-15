#include <iostream>
#include <string>
using namespace std;

class Service{
	public:
		virtual void request() = 0;
};

class RealService:public Service{
	public:
		void request(){
			cout << "RealService request" << endl;	
		}
};

class ProxyService:public Service{
	private:
		RealService *realService;
	public:
		ProxyService():realService(nullptr){}
		void request(){
			if(realService==nullptr)
				realService = new RealService();
			cout << "Here is Proxy Service and ";
			realService->request();	
		}
};

void Client(){
	RealService *real = new RealService();
	real->request();

	ProxyService *proxy = new ProxyService();
	proxy->request();
}

int main(){
	Client();

	return 0;
}
