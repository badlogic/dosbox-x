/***********************************************************************
 *  i386-supp.c
 *
 *  Description:  Support functions for the i386 GDB target stub.
 *
 *  Credits:      Created by Jonathan Brogdon
 *
 *  Terms of use:  This software is provided for use under the terms
 *                 and conditions of the GNU General Public License.
 *                 You should have received a copy of the GNU General
 *                 Public License along with this program; if not, write
 *                 to the Free Software Foundation, Inc., 59 Temple Place
 *                 Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Global Data:  None.
 *  Global Functions:
 *    gdb_serial_init
 *    gdb_target_init
 *    gdb_target_close
 *    putDebugChar
 *    getDebugChar
 *
 *  History
 *  Engineer:           Date:              Notes:
 *  ---------           -----              ------
 *  Jonathan Brogdon    061700             Genesis
 *
 ***********************************************************************/
#include <bios.h>
#include <stdlib.h>
#include "i386-stub.h"
#include "i386-stub.h"

/*
 *  Static Data
 */
static unsigned int gdbComPort      = 1;

/***********************************************************************
 *  gdb_serial_init
 *
 *  Description:  Initializes the serial port for remote debugging.
 *
 *  Inputs:
 *    port        - the PC COM port to use.
 *    speed       - the COM port speed.
 *  Outputs:  None.
 *  Returns:  None.
 *
 ***********************************************************************/
void gdb_serial_init(unsigned int port)
{
  gdbComPort = port;
}

/***********************************************************************
 *  gdb_target_init
 *
 *  Description:  This function inializes the GDB target.
 *
 *  Inputs:   None.
 *  Outputs:  None.
 *  Returns:  None.
 *
 ***********************************************************************/
void gdb_target_init(void)
{
  set_debug_traps();
  atexit(restore_traps);
}

/***********************************************************************
 *  gdb_target_close
 *
 *  Description:  This function closes the GDB target.
 *
 *  Inputs:   None.
 *  Outputs:  None.
 *  Returns:  None.
 *
 ***********************************************************************/
void gdb_target_close(void)
{
  restore_traps();
}

/***********************************************************************
 *  putDebugChar
 *
 *  Description:  sends a character to the debug COM port.
 *
 *  Inputs:
 *    c           - the data character to be sent
 *  Outputs:  None.
 *  Returns:  None.
 *
 ***********************************************************************/
void putDebugChar(char c)
{
  _bios_serialcom(_COM_SEND, gdbComPort-1, c);
}

/***********************************************************************
 *  getDebugChar
 *
 *  Description:  gets a character from the debug COM port.
 *
 *  Inputs:   None.
 *  Outputs:  None.
 *  Returns:  character data from the serial support.
 *
 ***********************************************************************/
int getDebugChar(void)
{
  return(_bios_serialcom(_COM_RECEIVE, gdbComPort-1, 0) & 0xff);
}















