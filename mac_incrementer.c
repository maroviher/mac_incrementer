/*
Use like this:
echo "$(cat /tmp/mac.txt | ./mac_incrementer)" > /tmp/mac.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int iRet = EXIT_FAILURE;
	char buffer[18];
	char* chRes = fgets(buffer, sizeof(buffer), stdin);
	if(chRes)
	{
		union GateWayMAC
		{
			unsigned long long int intGateWayMAC;
			unsigned char binGateWayMAC[8];
		};

		union GateWayMAC gateWayMAC;
		if (6 == sscanf((const char *) buffer, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
						&gateWayMAC.binGateWayMAC[5],
						&gateWayMAC.binGateWayMAC[4],
						&gateWayMAC.binGateWayMAC[3],
						&gateWayMAC.binGateWayMAC[2],
						&gateWayMAC.binGateWayMAC[1],
						&gateWayMAC.binGateWayMAC[0]))
		{
			gateWayMAC.intGateWayMAC++;
			sprintf(buffer, "%02X:%02X:%02X:%02X:%02X:%02X",
					gateWayMAC.binGateWayMAC[5],
					gateWayMAC.binGateWayMAC[4],
					gateWayMAC.binGateWayMAC[3],
					gateWayMAC.binGateWayMAC[2],
					gateWayMAC.binGateWayMAC[1],
					gateWayMAC.binGateWayMAC[0]);
			iRet = EXIT_SUCCESS;
		}
		fprintf(stdout, "%s", buffer);
	}
	return iRet;
}
