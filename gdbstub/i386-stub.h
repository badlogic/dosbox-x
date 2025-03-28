/****************************************************************************
 *
 *  i386-stub.h
 *
 *  Description:  Data definitions and constants for low level
 *                GDB server support.
 * 
 *  Terms of use:  This software is provided for use under the terms
 *                 and conditions of the GNU General Public License.
 *                 You should have received a copy of the GNU General
 *                 Public License along with this program; if not, write
 *                 to the Free Software Foundation, Inc., 59 Temple Place
 *                 Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Credits:      Created by Jonathan Brogdon
 *
 *  History
 *  Engineer:           Date:              Notes:
 *  ---------           -----              ------
 *  Jonathan Brogdon    061700             Genesis
 *
 ****************************************************************************/
#ifndef _I386_STUB_H_
#define _I386_STUB_H_

extern void gdb_serial_init(unsigned int port);
extern void gdb_target_init(void);
extern void gdb_target_close(void);

extern void set_debug_traps(void);
extern void restore_traps(void);
extern void breakpoint(void);

#endif /* _I386_STUB_H_ */
