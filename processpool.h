/*
*Author:GeneralSandman
*Code:https://github.com/GeneralSandman/TinyWeb
*E-mail:generalsandman@163.com
*Web:www.generalsandman.cn
*/

/*---XXX---
*
****************************************
*
*/

#ifndef PROCESS_POOL_H
#define PROCESS_POOL_H

#include "process.h"
#include "api.h"

#include <vector>
#include <map>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

class Master;
class Worker;

class ProcessPool
{
  private:
    Master *m_pMaster;
    std::map<Process *, ProcStatus> m_nProcess;

  public:
    ProcessPool(Master *);
    void start(int nums);
    ~ProcessPool();
};

#endif

// static int m_nProNums;
// static bool m_nStarted;
// static bool m_nStoped;

// static void m_fSetupSigHandler(void)
// {
//     add_signal(SIGHUP, m_fSignalHandler);
//     add_signal(SIGCHLD, m_fSignalHandler);
//     add_signal(SIGTERM, m_fSignalHandler);
//     add_signal(SIGINT, m_fSignalHandler);
//     add_signal(SIGPIPE, m_fSignalHandler);
// }

// static void m_fSignalHandler(int sig)
// {
//     int old_error = errno;
//     std::cout << "receive signal " << sig << std::endl;

//     switch (sig)
//     {
//     case SIGCHLD:
//     {
//         pid_t pid;
//         int stat;
//         while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
//         {
//             for (auto t : m_nProcess)
//             {
//                 if (t.first->getPid() == pid)
//                 {
//                     std::cout << "child " << pid << " join" << std::endl;
//                     t.second = Status_Exited;
//                 }
//             }
//         }

//         m_nStoped = true;
//         for (auto t : m_nProcess)
//         {
//             if (t.second == Status_Started)
//             {
//                 m_nStoped = false;
//                 break;
//             }
//         }
//         break;
//     }
//     case SIGTERM:
//     case SIGINT:
//     {
//         //kill all
//         std::cout << "kill all the child\n";
//         for (auto t : m_nProcess)
//         {
//             if (t.second == Status_Started)
//             {
//                 int pid = t.first->getPid();
//                 kill(pid, SIGTERM);
//                 t.second = Status_Exited;
//                 break;
//             }
//         }
//         break;
//     }
//     default:
//     {
//         break;
//     }
//     }
//     errno = old_error;
// }