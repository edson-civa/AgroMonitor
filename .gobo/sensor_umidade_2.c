#include "sensor_umidade.h"

#ifdef __cplusplus
extern "C" {
#endif

T0* GE_boxed1(TC* ac, T1 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb1));
	((T0*)(R))->id = 1;
	((Tb1*)(R))->p1 = &(((Tb1*)(R))->z1);
	((Tb1*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer1(TC* ac, volatile T1* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb1));
	((T0*)(R))->id = 1;
	((Tb1*)(R))->p1 = (T1*)a1;
	((Tb1*)(R))->z1 = *(T1*)a1;
	return R;
}

T0* GE_boxed2(TC* ac, T2 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb2));
	((T0*)(R))->id = 2;
	((Tb2*)(R))->p1 = &(((Tb2*)(R))->z1);
	((Tb2*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer2(TC* ac, volatile T2* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb2));
	((T0*)(R))->id = 2;
	((Tb2*)(R))->p1 = (T2*)a1;
	((Tb2*)(R))->z1 = *(T2*)a1;
	return R;
}

T0* GE_boxed3(TC* ac, T3 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb3));
	((T0*)(R))->id = 3;
	((Tb3*)(R))->p1 = &(((Tb3*)(R))->z1);
	((Tb3*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer3(TC* ac, volatile T3* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb3));
	((T0*)(R))->id = 3;
	((Tb3*)(R))->p1 = (T3*)a1;
	((Tb3*)(R))->z1 = *(T3*)a1;
	return R;
}

T0* GE_boxed4(TC* ac, T4 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb4));
	((T0*)(R))->id = 4;
	((Tb4*)(R))->p1 = &(((Tb4*)(R))->z1);
	((Tb4*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer4(TC* ac, volatile T4* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb4));
	((T0*)(R))->id = 4;
	((Tb4*)(R))->p1 = (T4*)a1;
	((Tb4*)(R))->z1 = *(T4*)a1;
	return R;
}

T0* GE_boxed5(TC* ac, T5 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb5));
	((T0*)(R))->id = 5;
	((Tb5*)(R))->p1 = &(((Tb5*)(R))->z1);
	((Tb5*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer5(TC* ac, volatile T5* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb5));
	((T0*)(R))->id = 5;
	((Tb5*)(R))->p1 = (T5*)a1;
	((Tb5*)(R))->z1 = *(T5*)a1;
	return R;
}

T0* GE_boxed6(TC* ac, T6 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb6));
	((T0*)(R))->id = 6;
	((Tb6*)(R))->p1 = &(((Tb6*)(R))->z1);
	((Tb6*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer6(TC* ac, volatile T6* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb6));
	((T0*)(R))->id = 6;
	((Tb6*)(R))->p1 = (T6*)a1;
	((Tb6*)(R))->z1 = *(T6*)a1;
	return R;
}

T0* GE_boxed7(TC* ac, T7 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb7));
	((T0*)(R))->id = 7;
	((Tb7*)(R))->p1 = &(((Tb7*)(R))->z1);
	((Tb7*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer7(TC* ac, volatile T7* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb7));
	((T0*)(R))->id = 7;
	((Tb7*)(R))->p1 = (T7*)a1;
	((Tb7*)(R))->z1 = *(T7*)a1;
	return R;
}

T0* GE_boxed8(TC* ac, T8 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb8));
	((T0*)(R))->id = 8;
	((Tb8*)(R))->p1 = &(((Tb8*)(R))->z1);
	((Tb8*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer8(TC* ac, volatile T8* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb8));
	((T0*)(R))->id = 8;
	((Tb8*)(R))->p1 = (T8*)a1;
	((Tb8*)(R))->z1 = *(T8*)a1;
	return R;
}

T0* GE_boxed9(TC* ac, T9 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb9));
	((T0*)(R))->id = 9;
	((Tb9*)(R))->p1 = &(((Tb9*)(R))->z1);
	((Tb9*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer9(TC* ac, volatile T9* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb9));
	((T0*)(R))->id = 9;
	((Tb9*)(R))->p1 = (T9*)a1;
	((Tb9*)(R))->z1 = *(T9*)a1;
	return R;
}

T0* GE_boxed10(TC* ac, T10 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb10));
	((T0*)(R))->id = 10;
	((Tb10*)(R))->p1 = &(((Tb10*)(R))->z1);
	((Tb10*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer10(TC* ac, volatile T10* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb10));
	((T0*)(R))->id = 10;
	((Tb10*)(R))->p1 = (T10*)a1;
	((Tb10*)(R))->z1 = *(T10*)a1;
	return R;
}

T0* GE_boxed11(TC* ac, T11 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb11));
	((T0*)(R))->id = 11;
	((Tb11*)(R))->p1 = &(((Tb11*)(R))->z1);
	((Tb11*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer11(TC* ac, volatile T11* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb11));
	((T0*)(R))->id = 11;
	((Tb11*)(R))->p1 = (T11*)a1;
	((Tb11*)(R))->z1 = *(T11*)a1;
	return R;
}

T0* GE_boxed12(TC* ac, T12 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb12));
	((T0*)(R))->id = 12;
	((Tb12*)(R))->p1 = &(((Tb12*)(R))->z1);
	((Tb12*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer12(TC* ac, volatile T12* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb12));
	((T0*)(R))->id = 12;
	((Tb12*)(R))->p1 = (T12*)a1;
	((Tb12*)(R))->z1 = *(T12*)a1;
	return R;
}

T0* GE_boxed13(TC* ac, T13 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb13));
	((T0*)(R))->id = 13;
	((Tb13*)(R))->p1 = &(((Tb13*)(R))->z1);
	((Tb13*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer13(TC* ac, volatile T13* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb13));
	((T0*)(R))->id = 13;
	((Tb13*)(R))->p1 = (T13*)a1;
	((Tb13*)(R))->z1 = *(T13*)a1;
	return R;
}

T0* GE_boxed14(TC* ac, T14 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb14));
	((T0*)(R))->id = 14;
	((Tb14*)(R))->p1 = &(((Tb14*)(R))->z1);
	((Tb14*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer14(TC* ac, volatile T14* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb14));
	((T0*)(R))->id = 14;
	((Tb14*)(R))->p1 = (T14*)a1;
	((Tb14*)(R))->z1 = *(T14*)a1;
	return R;
}

T0* GE_boxed71(TC* ac, T71 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb71));
	((T0*)(R))->id = 71;
	((Tb71*)(R))->p1 = &(((Tb71*)(R))->z1);
	((Tb71*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer71(TC* ac, T71* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb71));
	((T0*)(R))->id = 71;
	((Tb71*)(R))->p1 = (T71*)a1;
	((Tb71*)(R))->z1 = *(T71*)a1;
	return R;
}

T0* GE_boxed102(TC* ac, T102 a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb102));
	((T0*)(R))->id = 102;
	((Tb102*)(R))->p1 = &(((Tb102*)(R))->z1);
	((Tb102*)(R))->z1 = a1;
	return R;
}

T0* GE_boxed_pointer102(TC* ac, T102* a1)
{
	T0* R;
	R = (T0*)GE_calloc(1, sizeof(Tb102));
	((T0*)(R))->id = 102;
	((Tb102*)(R))->p1 = (T102*)a1;
	((Tb102*)(R))->z1 = *(T102*)a1;
	return R;
}

T71 GE_default71 = {0};
T102 GE_default102 = {0};

T0* GE_new_str8(T6 c)
{
	T0* R;
	TC* ac = GE_current_context();
	T0* t1;
	t1 = GE_new15(ac, c+1, EIF_TRUE);
	R = GE_new17(ac, EIF_TRUE);
	((T17*)(R))->a1 = t1;
	return R;
}

T0* GE_new_str32(T6 c)
{
	T0* R;
	TC* ac = GE_current_context();
	R = EIF_VOID;
	return R;
}

T0* GE_new_istr8(T6 c)
{
	T0* R;
	TC* ac = GE_current_context();
	R = EIF_VOID;
	return R;
}

T0* GE_new_istr32(T6 c)
{
	T0* R;
	TC* ac = GE_current_context();
	R = EIF_VOID;
	return R;
}

T14 GE_sp8_base_address(T0* a1)
{
	return (T14)(((T15*)(a1))->z2);
}

T14 GE_sp32_base_address(T0* a1)
{
	return (T14)(a1);
}

/* New instance of type BOOLEAN */
T0* GE_new1(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb1);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 1;
		((Tb1*)(R))->p1 = &(((Tb1*)(R))->z1);
	}
	return R;
}

/* New instance of type CHARACTER_8 */
T0* GE_new2(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb2);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 2;
		((Tb2*)(R))->p1 = &(((Tb2*)(R))->z1);
	}
	return R;
}

/* New instance of type CHARACTER_32 */
T0* GE_new3(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb3);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 3;
		((Tb3*)(R))->p1 = &(((Tb3*)(R))->z1);
	}
	return R;
}

/* New instance of type INTEGER_8 */
T0* GE_new4(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb4);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 4;
		((Tb4*)(R))->p1 = &(((Tb4*)(R))->z1);
	}
	return R;
}

/* New instance of type INTEGER_16 */
T0* GE_new5(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb5);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 5;
		((Tb5*)(R))->p1 = &(((Tb5*)(R))->z1);
	}
	return R;
}

/* New instance of type INTEGER_32 */
T0* GE_new6(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb6);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 6;
		((Tb6*)(R))->p1 = &(((Tb6*)(R))->z1);
	}
	return R;
}

/* New instance of type INTEGER_64 */
T0* GE_new7(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb7);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 7;
		((Tb7*)(R))->p1 = &(((Tb7*)(R))->z1);
	}
	return R;
}

/* New instance of type NATURAL_8 */
T0* GE_new8(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb8);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 8;
		((Tb8*)(R))->p1 = &(((Tb8*)(R))->z1);
	}
	return R;
}

/* New instance of type NATURAL_16 */
T0* GE_new9(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb9);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 9;
		((Tb9*)(R))->p1 = &(((Tb9*)(R))->z1);
	}
	return R;
}

/* New instance of type NATURAL_32 */
T0* GE_new10(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb10);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 10;
		((Tb10*)(R))->p1 = &(((Tb10*)(R))->z1);
	}
	return R;
}

/* New instance of type NATURAL_64 */
T0* GE_new11(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb11);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 11;
		((Tb11*)(R))->p1 = &(((Tb11*)(R))->z1);
	}
	return R;
}

/* New instance of type REAL_32 */
T0* GE_new12(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb12);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 12;
		((Tb12*)(R))->p1 = &(((Tb12*)(R))->z1);
	}
	return R;
}

/* New instance of type REAL_64 */
T0* GE_new13(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb13);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 13;
		((Tb13*)(R))->p1 = &(((Tb13*)(R))->z1);
	}
	return R;
}

/* New instance of type POINTER */
T0* GE_new14(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb14);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 14;
		((Tb14*)(R))->p1 = &(((Tb14*)(R))->z1);
	}
	return R;
}

/* New instance of type SPECIAL [CHARACTER_8] */
T0* GE_new15(TC* ac, T6 a1, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T15)+a1*sizeof(T2);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 15;
		((T15*)(R))->a1 = a1;
	}
	return R;
}

/* New instance of type STRING_8 */
T0* GE_new17(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T17);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 17;
	}
	return R;
}

/* New instance of type ISE_EXCEPTION_MANAGER */
T0* GE_new21(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T21);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 21;
	}
	return R;
}

/* New instance of type SENSOR_UMIDADE */
T0* GE_new26(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T26);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 26;
	}
	return R;
}

/* New instance of type CELL [detachable EXCEPTION] */
T0* GE_new27(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T27);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 27;
	}
	return R;
}

/* New instance of type HASH_TABLE [INTEGER_32, INTEGER_32] */
T0* GE_new28(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T28);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 28;
	}
	return R;
}

/* New instance of type CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]] */
T0* GE_new29(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T29);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 29;
	}
	return R;
}

/* New instance of type CELL [NO_MORE_MEMORY] */
T0* GE_new30(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T30);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 30;
	}
	return R;
}

/* New instance of type C_STRING */
T0* GE_new31(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T31);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 31;
	}
	return R;
}

/* New instance of type TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN] */
T0* GE_new32(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T32);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 32;
	}
	return R;
}

/* New instance of type VOID_TARGET */
T0* GE_new33(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T33);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 33;
	}
	return R;
}

/* New instance of type ROUTINE_FAILURE */
T0* GE_new35(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T35);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 35;
	}
	return R;
}

/* New instance of type OLD_VIOLATION */
T0* GE_new37(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T37);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 37;
	}
	return R;
}

/* New instance of type NO_MORE_MEMORY */
T0* GE_new39(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T39);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 39;
	}
	return R;
}

/* New instance of type INVARIANT_VIOLATION */
T0* GE_new40(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T40);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 40;
	}
	return R;
}

/* New instance of type OPERATING_SYSTEM_SIGNAL_FAILURE */
T0* GE_new41(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T41);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 41;
	}
	return R;
}

/* New instance of type IO_FAILURE */
T0* GE_new42(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T42);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 42;
	}
	return R;
}

/* New instance of type OPERATING_SYSTEM_FAILURE */
T0* GE_new43(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T43);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 43;
	}
	return R;
}

/* New instance of type COM_FAILURE */
T0* GE_new44(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T44);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 44;
	}
	return R;
}

/* New instance of type EIFFEL_RUNTIME_PANIC */
T0* GE_new45(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T45);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 45;
	}
	return R;
}

/* New instance of type PRECONDITION_VIOLATION */
T0* GE_new48(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T48);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 48;
	}
	return R;
}

/* New instance of type POSTCONDITION_VIOLATION */
T0* GE_new49(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T49);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 49;
	}
	return R;
}

/* New instance of type FLOATING_POINT_FAILURE */
T0* GE_new50(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T50);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 50;
	}
	return R;
}

/* New instance of type CHECK_VIOLATION */
T0* GE_new51(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T51);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 51;
	}
	return R;
}

/* New instance of type BAD_INSPECT_VALUE */
T0* GE_new52(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T52);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 52;
	}
	return R;
}

/* New instance of type VARIANT_VIOLATION */
T0* GE_new53(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T53);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 53;
	}
	return R;
}

/* New instance of type LOOP_INVARIANT_VIOLATION */
T0* GE_new54(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T54);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 54;
	}
	return R;
}

/* New instance of type RESCUE_FAILURE */
T0* GE_new55(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T55);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 55;
	}
	return R;
}

/* New instance of type RESUMPTION_FAILURE */
T0* GE_new56(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T56);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 56;
	}
	return R;
}

/* New instance of type CREATE_ON_DEFERRED */
T0* GE_new57(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T57);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 57;
	}
	return R;
}

/* New instance of type EXTERNAL_FAILURE */
T0* GE_new58(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T58);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 58;
	}
	return R;
}

/* New instance of type VOID_ASSIGNED_TO_EXPANDED */
T0* GE_new59(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T59);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 59;
	}
	return R;
}

/* New instance of type EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
T0* GE_new60(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T60);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 60;
	}
	return R;
}

/* New instance of type MISMATCH_FAILURE */
T0* GE_new61(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T61);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 61;
	}
	return R;
}

/* New instance of type DEVELOPER_EXCEPTION */
T0* GE_new62(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T62);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 62;
	}
	return R;
}

/* New instance of type ADDRESS_APPLIED_TO_MELTED_FEATURE */
T0* GE_new63(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T63);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 63;
	}
	return R;
}

/* New instance of type SERIALIZATION_FAILURE */
T0* GE_new64(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T64);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 64;
	}
	return R;
}

/* New instance of type PRIMES */
T0* GE_new65(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T65);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 65;
	}
	return R;
}

/* New instance of type SPECIAL [INTEGER_32] */
T0* GE_new66(TC* ac, T6 a1, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T66)+a1*sizeof(T6);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 66;
		((T66*)(R))->a1 = a1;
	}
	return R;
}

/* New instance of type SPECIAL [BOOLEAN] */
T0* GE_new67(TC* ac, T6 a1, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T67)+a1*sizeof(T1);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 67;
		((T67*)(R))->a1 = a1;
	}
	return R;
}

/* New instance of type UTF_CONVERTER */
T0* GE_new71(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb71);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 71;
		((Tb71*)(R))->p1 = &(((Tb71*)(R))->z1);
	}
	return R;
}

/* New instance of type CELL [INTEGER_32] */
T0* GE_new72(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T72);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 72;
	}
	return R;
}

/* New instance of type MANAGED_POINTER */
T0* GE_new73(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T73);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 73;
	}
	GE_register_dispose(R,&T73f6);
	return R;
}

/* New instance of type EXCEPTIONS */
T0* GE_new101(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(T101);
	R = (T0*)GE_calloc_atomic(1, s);
	if (initialize) {
		((T0*)(R))->id = 101;
	}
	return R;
}

/* New instance of type TYPED_POINTER [NATURAL_8] */
T0* GE_new102(TC* ac, T1 initialize)
{
	T0* R;
	size_t s = sizeof(Tb102);
	R = (T0*)GE_calloc(1, s);
	if (initialize) {
		((T0*)(R))->id = 102;
		((Tb102*)(R))->p1 = &(((Tb102*)(R))->z1);
	}
	return R;
}

/* SENSOR_UMIDADE.make */
T0* T26c2(TC* ac)
{
	GE_call tc = {"SENSOR_UMIDADE","make",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new26(ac, EIF_TRUE);
	((T26*)(C))->a1 = (T12)(0.0);
	ac->call = tc.caller;
	return C;
}

/* ISE_EXCEPTION_MANAGER.set_exception_data */
void T21s16(TC* ac, T6 a1, T1 a2, T6 a3, T6 a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T0* a10, T6 a11, T1 a12)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","set_exception_data",ac->call};
	T0* t1;
	T0* t2;
	T1 t3;
	T0* m1 = 0;
	T0* m2 = 0;
	ac->call = &tc;
	t1 = (T21s6(ac));
	t2 = GE_mt32(ac, a1, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
	T29f2(ac, t1, t2);
	if (a2) {
		t1 = (T21s10(ac));
		t3 = (t1?((m1 = t1, EIF_TRUE)):EIF_FALSE);
		if (t3) {
			T21s17(ac, m1);
		}
	} else {
		t1 = (T21s1(ac));
		t3 = (t1?((m2 = t1, EIF_TRUE)):EIF_FALSE);
		if (!(t3)) {
			GE_raise_with_message(GE_EX_CHECK, "last_exception_attached");
		}
		T22x4669463T0(ac, m2, a10);
		T22x4669467T0(ac, m2, a6);
		T22x4669464T0(ac, m2, a7);
	}
	ac->call = tc.caller;
}

/* NO_MORE_MEMORY.set_type_name */
void T39f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_type_name",ac->call};
	ac->call = &tc;
	((T39*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.set_type_name */
void T64f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"SERIALIZATION_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T64*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* OLD_VIOLATION.set_type_name */
void T37f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OLD_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T37*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* COM_FAILURE.set_type_name */
void T44f24(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T44*)(C))->a8 = a1;
	ac->call = tc.caller;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_type_name */
void T63f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","set_type_name",ac->call};
	ac->call = &tc;
	((T63*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.set_type_name */
void T62f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","set_type_name",ac->call};
	ac->call = &tc;
	((T62*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* MISMATCH_FAILURE.set_type_name */
void T61f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"MISMATCH_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T61*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_type_name */
void T43f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T43*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.set_type_name */
void T42f20(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"IO_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T42*)(C))->a7 = a1;
	ac->call = tc.caller;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_type_name */
void T60f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T60*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* VOID_ASSIGNED_TO_EXPANDED.set_type_name */
void T59f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","set_type_name",ac->call};
	ac->call = &tc;
	((T59*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* EXTERNAL_FAILURE.set_type_name */
void T58f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXTERNAL_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T58*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* CREATE_ON_DEFERRED.set_type_name */
void T57f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CREATE_ON_DEFERRED","set_type_name",ac->call};
	ac->call = &tc;
	((T57*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* RESUMPTION_FAILURE.set_type_name */
void T56f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESUMPTION_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T56*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* RESCUE_FAILURE.set_type_name */
void T55f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESCUE_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T55*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.set_type_name */
void T45f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_type_name",ac->call};
	ac->call = &tc;
	((T45*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_type_name */
void T41f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T41*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* LOOP_INVARIANT_VIOLATION.set_type_name */
void T54f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T54*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* VARIANT_VIOLATION.set_type_name */
void T53f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VARIANT_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T53*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* BAD_INSPECT_VALUE.set_type_name */
void T52f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"BAD_INSPECT_VALUE","set_type_name",ac->call};
	ac->call = &tc;
	((T52*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_type_name */
void T35f20(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T35*)(C))->a7 = a1;
	ac->call = tc.caller;
}

/* CHECK_VIOLATION.set_type_name */
void T51f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CHECK_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T51*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_type_name */
void T40f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T40*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* FLOATING_POINT_FAILURE.set_type_name */
void T50f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","set_type_name",ac->call};
	ac->call = &tc;
	((T50*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* POSTCONDITION_VIOLATION.set_type_name */
void T49f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T49*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* PRECONDITION_VIOLATION.set_type_name */
void T48f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"PRECONDITION_VIOLATION","set_type_name",ac->call};
	ac->call = &tc;
	((T48*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* VOID_TARGET.set_type_name */
void T33f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_TARGET","set_type_name",ac->call};
	ac->call = &tc;
	((T33*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* NO_MORE_MEMORY.set_recipient_name */
void T39f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_recipient_name",ac->call};
	ac->call = &tc;
	((T39*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.set_recipient_name */
void T64f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"SERIALIZATION_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T64*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* OLD_VIOLATION.set_recipient_name */
void T37f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OLD_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T37*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* COM_FAILURE.set_recipient_name */
void T44f23(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T44*)(C))->a7 = a1;
	ac->call = tc.caller;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_recipient_name */
void T63f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T63*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.set_recipient_name */
void T62f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T62*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* MISMATCH_FAILURE.set_recipient_name */
void T61f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"MISMATCH_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T61*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_recipient_name */
void T43f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T43*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.set_recipient_name */
void T42f19(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"IO_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T42*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_recipient_name */
void T60f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T60*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* VOID_ASSIGNED_TO_EXPANDED.set_recipient_name */
void T59f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","set_recipient_name",ac->call};
	ac->call = &tc;
	((T59*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* EXTERNAL_FAILURE.set_recipient_name */
void T58f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXTERNAL_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T58*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* CREATE_ON_DEFERRED.set_recipient_name */
void T57f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CREATE_ON_DEFERRED","set_recipient_name",ac->call};
	ac->call = &tc;
	((T57*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* RESUMPTION_FAILURE.set_recipient_name */
void T56f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESUMPTION_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T56*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* RESCUE_FAILURE.set_recipient_name */
void T55f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESCUE_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T55*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.set_recipient_name */
void T45f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_recipient_name",ac->call};
	ac->call = &tc;
	((T45*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_recipient_name */
void T41f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T41*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* LOOP_INVARIANT_VIOLATION.set_recipient_name */
void T54f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T54*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* VARIANT_VIOLATION.set_recipient_name */
void T53f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VARIANT_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T53*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* BAD_INSPECT_VALUE.set_recipient_name */
void T52f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"BAD_INSPECT_VALUE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T52*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_recipient_name */
void T35f19(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T35*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* CHECK_VIOLATION.set_recipient_name */
void T51f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CHECK_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T51*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_recipient_name */
void T40f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T40*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* FLOATING_POINT_FAILURE.set_recipient_name */
void T50f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","set_recipient_name",ac->call};
	ac->call = &tc;
	((T50*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* POSTCONDITION_VIOLATION.set_recipient_name */
void T49f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T49*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* PRECONDITION_VIOLATION.set_recipient_name */
void T48f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"PRECONDITION_VIOLATION","set_recipient_name",ac->call};
	ac->call = &tc;
	((T48*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* VOID_TARGET.set_recipient_name */
void T33f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_TARGET","set_recipient_name",ac->call};
	ac->call = &tc;
	((T33*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* NO_MORE_MEMORY.set_exception_trace */
void T39f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_exception_trace",ac->call};
	ac->call = &tc;
	((T39*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.set_exception_trace */
void T64f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"SERIALIZATION_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T64*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* OLD_VIOLATION.set_exception_trace */
void T37f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OLD_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T37*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* COM_FAILURE.set_exception_trace */
void T44f21(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T44*)(C))->a6 = a1;
	ac->call = tc.caller;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_exception_trace */
void T63f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T63*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.set_exception_trace */
void T62f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T62*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* MISMATCH_FAILURE.set_exception_trace */
void T61f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"MISMATCH_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T61*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_exception_trace */
void T43f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T43*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.set_exception_trace */
void T42f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"IO_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T42*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_exception_trace */
void T60f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T60*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* VOID_ASSIGNED_TO_EXPANDED.set_exception_trace */
void T59f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","set_exception_trace",ac->call};
	ac->call = &tc;
	((T59*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* EXTERNAL_FAILURE.set_exception_trace */
void T58f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXTERNAL_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T58*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* CREATE_ON_DEFERRED.set_exception_trace */
void T57f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CREATE_ON_DEFERRED","set_exception_trace",ac->call};
	ac->call = &tc;
	((T57*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* RESUMPTION_FAILURE.set_exception_trace */
void T56f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESUMPTION_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T56*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* RESCUE_FAILURE.set_exception_trace */
void T55f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESCUE_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T55*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.set_exception_trace */
void T45f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_exception_trace",ac->call};
	ac->call = &tc;
	((T45*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_exception_trace */
void T41f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T41*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* LOOP_INVARIANT_VIOLATION.set_exception_trace */
void T54f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T54*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* VARIANT_VIOLATION.set_exception_trace */
void T53f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VARIANT_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T53*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* BAD_INSPECT_VALUE.set_exception_trace */
void T52f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"BAD_INSPECT_VALUE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T52*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_exception_trace */
void T35f17(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T35*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* CHECK_VIOLATION.set_exception_trace */
void T51f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CHECK_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T51*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_exception_trace */
void T40f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T40*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* FLOATING_POINT_FAILURE.set_exception_trace */
void T50f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","set_exception_trace",ac->call};
	ac->call = &tc;
	((T50*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* POSTCONDITION_VIOLATION.set_exception_trace */
void T49f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T49*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* PRECONDITION_VIOLATION.set_exception_trace */
void T48f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"PRECONDITION_VIOLATION","set_exception_trace",ac->call};
	ac->call = &tc;
	((T48*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* VOID_TARGET.set_exception_trace */
void T33f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_TARGET","set_exception_trace",ac->call};
	ac->call = &tc;
	((T33*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* ISE_EXCEPTION_MANAGER.set_last_exception */
void T21s17(TC* ac, T0* a1)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","set_last_exception",ac->call};
	T0* t1;
	ac->call = &tc;
	t1 = (T21s2(ac));
	T27f2(ac, t1, a1);
	ac->call = tc.caller;
}

/* CELL [detachable EXCEPTION].put */
void T27f2(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CELL","put",ac->call};
	ac->call = &tc;
	((T27*)(C))->a1 = a1;
	ac->call = tc.caller;
}

/* CELL [detachable EXCEPTION].put */
T0* T27c2(TC* ac, T0* a1)
{
	GE_call tc = {"CELL","put",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new27(ac, EIF_TRUE);
	((T27*)(C))->a1 = a1;
	ac->call = tc.caller;
	return C;
}

/* ISE_EXCEPTION_MANAGER.last_exception_cell */
T0* T21s2(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","last_exception_cell",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	if (GE_process_onces->reference_status[0]) {
		if (GE_process_onces->reference_exception[0]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[0]);
		}
		return GE_process_onces->reference_value[0];
	} else {
		GE_process_onces->reference_status[0] = '\1';
		GE_process_onces->reference_value[0] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[0] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	R = T27c2(ac, EIF_VOID);
	GE_process_onces->reference_value[0] = R;
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.exception_from_data */
T0* T21s10(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","exception_from_data",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	T0* t2;
	T6 t3;
	T0* m1 = 0;
	T0* m2 = 0;
	T0* m3 = 0;
	T0* m4 = 0;
	T0* m5 = 0;
	T0* m6 = 0;
	T0* m7 = 0;
	T0* m8 = 0;
	T0* m9 = 0;
	ac->call = &tc;
	t2 = (T21s11(ac));
	t1 = (t2?((m1 = t2, EIF_TRUE)):EIF_FALSE);
	if (t1) {
		t3 = (((T32*)(m1))->z1);
		t2 = (T21s12(ac, t3));
		t1 = (t2?((m2 = t2, EIF_TRUE)):EIF_FALSE);
	}
	if (t1) {
		t1 = (m2?((m3 = m2, T21s10ot1(ac, m2))):EIF_FALSE);
		if (t1) {
			l1 = (T21s1(ac));
			t1 = (T1)(l1!=EIF_VOID);
			if (t1) {
				T22x4669468T0(ac, m2, l1);
			}
			t2 = (((T32*)(m1))->z7);
			T35f14(ac, m3, t2);
			t2 = (((T32*)(m1))->z8);
			T35f15(ac, m3, t2);
		} else {
			t1 = (m2?((m4 = m2, T21s10ot2(ac, m2))):EIF_FALSE);
			if (t1) {
				l1 = (T21s1(ac));
				t1 = (T1)(l1!=EIF_VOID);
				if (t1) {
					T22x4669468T0(ac, m2, l1);
				}
			} else {
				t1 = (m2?((m5 = m2, T21s10ot3(ac, m2))):EIF_FALSE);
				if (t1) {
					t1 = (((T32*)(m1))->z11);
					T40f14(ac, m5, t1);
				} else {
					t1 = (m2?((m6 = m2, T21s10ot4(ac, m2))):EIF_FALSE);
					if (t1) {
						t3 = (((T32*)(m1))->z2);
						T41f14(ac, m6, t3);
					} else {
						t1 = (m2?((m7 = m2, T21s10ot5(ac, m2))):EIF_FALSE);
						if (t1) {
							t3 = (((T32*)(m1))->z3);
							T42f16(ac, m7, t3);
						} else {
							t1 = (m2?((m8 = m2, T21s10ot6(ac, m2))):EIF_FALSE);
							if (t1) {
								t3 = (((T32*)(m1))->z3);
								T43f14(ac, m8, t3);
							} else {
								t1 = (m2?((m9 = m2, T21s10ot7(ac, m2))):EIF_FALSE);
								if (t1) {
									t3 = (((T32*)(m1))->z2);
									T44f19(ac, m9, t3);
									t2 = (((T32*)(m1))->z4);
									T44f20(ac, m9, t2);
								}
							}
						}
					}
				}
				t1 = (T21s8(ac));
				if (t1) {
					l1 = (T21s1(ac));
				}
				t1 = (T1)(l1==EIF_VOID);
				if (t1) {
					l1 = m2;
				}
				T22x4669468T0(ac, m2, l1);
			}
		}
		t2 = (((T32*)(m1))->z9);
		T22x4669463T0(ac, m2, t2);
		t2 = (((T32*)(m1))->z4);
		T22x4669469T0(ac, m2, t2);
		t2 = (((T32*)(m1))->z5);
		T22x4669467T0(ac, m2, t2);
		t2 = (((T32*)(m1))->z6);
		T22x4669464T0(ac, m2, t2);
		R = m2;
	}
	ac->call = tc.caller;
	return R;
}

T1 T21s10ot1(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 35:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot2(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 37:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot3(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 40:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot4(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 41:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot5(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 42:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot6(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 43:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

T1 T21s10ot7(TC* ac, T0* a1)
{
	switch (((T0*)(a1))->id) {
	case 44:
		return EIF_TRUE;
	default:
		return EIF_FALSE;
	}
}

/* NO_MORE_MEMORY.set_description */
void T39f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T39*)(C))->a1 = l3;
	} else {
		((T39*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* C_STRING.set_count */
void T31f5(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"C_STRING","set_count",ac->call};
	T6 l1 = 0;
	T6 t1;
	T1 t2;
	ac->call = &tc;
	l1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	t1 = (((T73*)(((T31*)(C))->a1))->a2);
	t2 = ((T1)((t1)<(l1)));
	if (t2) {
		T73f8(ac, ((T31*)(C))->a1, l1);
	}
	((T31*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* MANAGED_POINTER.resize */
void T73f8(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"MANAGED_POINTER","resize",ac->call};
	T1 t1;
	T6 t2;
	T14 volatile t3;
	T0* t4;
	ac->call = &tc;
	t1 = (T1)(!(T1)((a1) == (((T73*)(C))->a2)));
	if (t1) {
		t2 = (T6f4(ac, &a1, (T6)(GE_int32(1))));
		((T73*)(C))->a1 = (T14f5(ac, &(((T73*)(C))->a1), t2));
		t3 = (T73s4(ac));
		t1 = (T1)((((T73*)(C))->a1) == (t3));
		if (t1) {
			t4 = (T101c1(ac));
			T101s2(ac, GE_ms8("No more memory", 14));
		}
	}
	t1 = (T6f14(ac, &a1, ((T73*)(C))->a2));
	if (t1) {
		t3 = ((T14)(((char*)(((T73*)(C))->a1))+(((T73*)(C))->a2)));
		t2 = ((T6)((a1)-(((T73*)(C))->a2)));
		T14f12(ac, &t3, (T6)(GE_int32(0)), t2);
	}
	((T73*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* POINTER.memory_set */
void T14f12(TC* ac, T14 volatile* C, T6 a1, T6 a2)
{
	GE_call tc = {"POINTER","memory_set",ac->call};
	ac->call = &tc;
	T14s16(ac, *C, a1, a2);
	ac->call = tc.caller;
}

/* POINTER.c_memset */
void T14s16(TC* ac, T14 a1, T6 a2, T6 a3)
{
	GE_call tc = {"POINTER","c_memset",ac->call};
	ac->call = &tc;
	{
	memset((void *)(void*)a1,( int)a2,( size_t)a3);
	}
	ac->call = tc.caller;
}

/* INTEGER_32.is_greater */
T1 T6f14(TC* ac, T6 volatile* C, T6 a1)
{
	GE_call tc = {"INTEGER_32","is_greater",ac->call};
	T1 R = 0;
	ac->call = &tc;
	R = ((T1)((a1)<(*C)));
	ac->call = tc.caller;
	return R;
}

/* EXCEPTIONS.raise */
void T101s2(TC* ac, T0* a1)
{
	GE_call tc = {"EXCEPTIONS","raise",ac->call};
	T0* l1 = 0;
	ac->call = &tc;
	l1 = T62c11(ac);
	T62f14(ac, l1, a1);
	T62f17(ac, l1);
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.raise */
void T62f17(TC* ac, T0* C)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","raise",ac->call};
	T0* t1;
	ac->call = &tc;
	t1 = (T62s6(ac));
	T21s19(ac, C);
	ac->call = tc.caller;
}

/* ISE_EXCEPTION_MANAGER.raise */
void T21s19(TC* ac, T0* a1)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","raise",ac->call};
	T14 l1 = 0;
	T14 l2 = 0;
	T1 t1;
	T0* t2;
	T6 t3;
	T0* m1 = 0;
	ac->call = &tc;
	t1 = (T62f8(ac, a1));
	t1 = ((T1)(!(t1)));
	if (t1) {
		t1 = (T21s8(ac));
		if (t1) {
			t2 = (T21s1(ac));
			T62f12(ac, a1, t2);
		}
		T21s17(ac, a1);
		l1 = (T21s9(ac));
		t2 = (((T62*)(a1))->a1);
		t1 = (t2?((m1 = t2, EIF_TRUE)):EIF_FALSE);
		if (t1) {
			l2 = (T31f3(ac, m1));
		} else {
			l2 = (T21s9(ac));
		}
		t3 = (T62f9(ac, a1));
		GE_developer_raise((t3), (l1), (l2));
	}
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.code */
T6 T62f9(TC* ac, T0* C)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(24));
	ac->call = tc.caller;
	return R;
}

/* C_STRING.item */
T14 T31f3(TC* ac, T0* C)
{
	GE_call tc = {"C_STRING","item",ac->call};
	T14 R = 0;
	ac->call = &tc;
	R = (((T73*)(((T31*)(C))->a1))->a1);
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.default_pointer */
T14 T21s9(TC* ac)
{
	T14 R = 0;
	return R;
}

/* DEVELOPER_EXCEPTION.is_ignored */
T1 T62f8(TC* ac, T0* C)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T62s6(ac));
	t2 = ((T0*)&(GE_types[62][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.is_ignored */
T1 T21s13(TC* ac, T0* a1)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T6 t2;
	ac->call = &tc;
	t1 = (T21s3(ac));
	t2 = (T70x3883012(ac, a1));
	R = (T28f34(ac, t1, t2));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].has */
T1 T28f34(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","has",ac->call};
	T1 R = 0;
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 volatile l4 = 0;
	T6 l5 = 0;
	T6 l6 = 0;
	T6 l7 = 0;
	T6 l8 = 0;
	T0* l9 = 0;
	T0* l10 = 0;
	T0* l11 = 0;
	T6 l12 = 0;
	T1 t1;
	T6 t2;
	T6 t3;
	ac->call = &tc;
	l7 = (T6)(GE_int32(-1));
	t1 = (T1)((a1) == (l1));
	if (!(t1)) {
		t1 = EIF_FALSE;
	}
	if (t1) {
		if (((T28*)(C))->a11) {
			R = EIF_TRUE;
		}
	} else {
		l9 = ((T28*)(C))->a3;
		l10 = ((T28*)(C))->a5;
		l11 = ((T28*)(C))->a4;
		l6 = ((T28*)(C))->a1;
		l8 = l6;
		l2 = (T28f25(ac, C, a1));
		t2 = (T6)(GE_int32(1));
		t3 = ((T6)((l6)-((T6)(GE_int32(1)))));
		t3 = ((T6)((l2)%(t3)));
		l3 = ((T6)((t2)+(t3)));
		t2 = ((T6)((l2)%(l6)));
		l5 = ((T6)((t2)-(l3)));
		while (1) {
			t1 = (T1)((l8) == ((T6)(GE_int32(0))));
			if (t1) {
				break;
			}
			t2 = ((T6)((l5)+(l3)));
			l5 = ((T6)((t2)%(l6)));
			l4 = (((T66*)(l10))->z2[l5]);
			t1 = (T6f9(ac, (&l4), (T6)(GE_int32(0))));
			if (t1) {
				l12 = (((T66*)(l9))->z2[l4]);
				t1 = (T28f26(ac, C, l12, a1));
				if (t1) {
					l8 = (T6)(GE_int32(1));
					R = EIF_TRUE;
				}
			} else {
				t1 = (T1)((l4) == ((T6)(GE_int32(-1))));
				if (t1) {
					l8 = (T6)(GE_int32(1));
				} else {
					t1 = (T1)((l7) == ((T6)(GE_int32(-1))));
					if (t1) {
						t2 = ((T6)(-(l4)));
						l4 = ((T6)((t2)+((T6)(GE_int32(-2)))));
						t1 = (((T67*)(l11))->z2[l4]);
						t1 = ((T1)(!(t1)));
						if (t1) {
							l8 = (T6)(GE_int32(1));
						} else {
							l7 = l5;
						}
					}
				}
			}
			l8 = ((T6)((l8)-((T6)(GE_int32(1)))));
		}
	}
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].same_keys */
T1 T28f26(TC* ac, T0* C, T6 a1, T6 a2)
{
	GE_call tc = {"HASH_TABLE","same_keys",ac->call};
	T1 R = 0;
	ac->call = &tc;
	R = (T1)((a1) == (a2));
	ac->call = tc.caller;
	return R;
}

/* INTEGER_32.is_greater_equal */
T1 T6f9(TC* ac, T6 volatile* C, T6 a1)
{
	GE_call tc = {"INTEGER_32","is_greater_equal",ac->call};
	T1 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((*C)<(a1)));
	R = ((T1)(!(t1)));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].hash_code_of */
T6 T28f25(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","hash_code_of",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6f13(ac, &a1));
	ac->call = tc.caller;
	return R;
}

/* INTEGER_32.hash_code */
T6 T6f13(TC* ac, T6 volatile* C)
{
	GE_call tc = {"INTEGER_32","hash_code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = ((T6)((*C)&((T6)(GE_int32(2147483647)))));
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable SERIALIZATION_FAILURE].type_id */
T6 T99f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable ADDRESS_APPLIED_TO_MELTED_FEATURE].type_id */
T6 T98f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable DEVELOPER_EXCEPTION].type_id */
T6 T97f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable MISMATCH_FAILURE].type_id */
T6 T96f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable EXCEPTION_IN_SIGNAL_HANDLER_FAILURE].type_id */
T6 T95f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable VOID_ASSIGNED_TO_EXPANDED].type_id */
T6 T94f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable EXTERNAL_FAILURE].type_id */
T6 T93f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable CREATE_ON_DEFERRED].type_id */
T6 T92f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable RESUMPTION_FAILURE].type_id */
T6 T91f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable RESCUE_FAILURE].type_id */
T6 T90f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable LOOP_INVARIANT_VIOLATION].type_id */
T6 T89f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable VARIANT_VIOLATION].type_id */
T6 T88f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable BAD_INSPECT_VALUE].type_id */
T6 T87f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable CHECK_VIOLATION].type_id */
T6 T86f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable FLOATING_POINT_FAILURE].type_id */
T6 T85f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable POSTCONDITION_VIOLATION].type_id */
T6 T84f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable PRECONDITION_VIOLATION].type_id */
T6 T83f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable EIFFEL_RUNTIME_PANIC].type_id */
T6 T82f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable COM_FAILURE].type_id */
T6 T81f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable OPERATING_SYSTEM_FAILURE].type_id */
T6 T80f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable IO_FAILURE].type_id */
T6 T79f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable OPERATING_SYSTEM_SIGNAL_FAILURE].type_id */
T6 T78f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable INVARIANT_VIOLATION].type_id */
T6 T77f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable NO_MORE_MEMORY].type_id */
T6 T76f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable OLD_VIOLATION].type_id */
T6 T75f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable ROUTINE_FAILURE].type_id */
T6 T74f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* TYPE [detachable VOID_TARGET].type_id */
T6 T69f1(TC* ac, T0* C)
{
	GE_call tc = {"TYPE","type_id",ac->call};
	T6 R = 0;
	ac->call = &tc;
	{
	R = ((EIF_TYPE_OBJ*)(C))->type_id;
	}
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.ignored_exceptions */
T0* T21s3(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","ignored_exceptions",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	if (GE_process_onces->reference_status[1]) {
		if (GE_process_onces->reference_exception[1]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[1]);
		}
		return GE_process_onces->reference_value[1];
	} else {
		GE_process_onces->reference_status[1] = '\1';
		GE_process_onces->reference_value[1] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[1] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	R = T28c35(ac, (T6)(GE_int32(0)));
	GE_process_onces->reference_value[1] = R;
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].make */
T0* T28c35(TC* ac, T6 a1)
{
	GE_call tc = {"HASH_TABLE","make",ac->call};
	T0* C;
	T0* l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 l4 = 0;
	T6 t1;
	ac->call = &tc;
	C = GE_new28(ac, EIF_TRUE);
	l1 = T65c5(ac);
	l4 = (T6f4(ac, &a1, (T6)(GE_int32(2))));
	t1 = ((T6)((l4)/((T6)(GE_int32(2)))));
	t1 = ((T6)((l4)+(t1)));
	l4 = ((T6)((t1)+((T6)(GE_int32(1)))));
	l4 = (T65s1(ac, l4));
	((T28*)(C))->a1 = l4;
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T28*)(C))->a2 = T66c4(ac, t1);
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T28*)(C))->a3 = T66c4(ac, t1);
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T28*)(C))->a4 = T67c4(ac, EIF_FALSE, t1);
	t1 = ((T6)((l4)+((T6)(GE_int32(1)))));
	((T28*)(C))->a5 = T66c5(ac, (T6)(GE_int32(-1)), t1);
	((T28*)(C))->a6 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T28*)(C))->a7 = (T6)(GE_int32(0));
	((T28*)(C))->a8 = (T6)(GE_int32(-1));
	((T28*)(C))->a9 = (T6)(GE_int32(0));
	((T28*)(C))->a10 = l2;
	((T28*)(C))->a11 = EIF_FALSE;
	((T28*)(C))->a12 = (T6)(GE_int32(0));
	((T28*)(C))->a13 = (T6)(GE_int32(2147483645));
	((T28*)(C))->a14 = l2;
	((T28*)(C))->a15 = l3;
	ac->call = tc.caller;
	return C;
}

/* SPECIAL [INTEGER_32].make_filled */
T0* T66c5(TC* ac, T6 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","make_filled",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new66(ac, a2, EIF_TRUE);
	T66f4(ac, C, a2);
	t1 = ((T6)((a2)-((T6)(GE_int32(1)))));
	T66f8(ac, C, a1, (T6)(GE_int32(0)), t1);
	ac->call = tc.caller;
	return C;
}

/* SPECIAL [INTEGER_32].fill_with */
void T66f8(TC* ac, T0* C, T6 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","fill_with",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 t1;
	T1 t2;
	ac->call = &tc;
	l1 = a2;
	t1 = ((T6)((a3)+((T6)(GE_int32(1)))));
	l3 = (T6f12(ac, &(((T66*)(C))->a2), t1));
	l2 = l3;
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		((T66*)(C))->z2[l1] = (a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	l1 = l3;
	l2 = ((T6)((a3)+((T6)(GE_int32(1)))));
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		T66f9(ac, C, a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
}

/* SPECIAL [INTEGER_32].extend */
void T66f9(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"SPECIAL","extend",ac->call};
	T6 t1;
	ac->call = &tc;
	{
	t1 = ((T66*)(C))->a2;
	((T66*)(C))->a2 = t1 + 1;
	((T66*)(C))->z2[t1] = a1;
	}
	ac->call = tc.caller;
}

/* INTEGER_32.min */
T6 T6f12(TC* ac, T6 volatile* C, T6 a1)
{
	GE_call tc = {"INTEGER_32","min",ac->call};
	T6 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = (T6f15(ac, C, a1));
	if (t1) {
		R = *C;
	} else {
		R = a1;
	}
	ac->call = tc.caller;
	return R;
}

/* INTEGER_32.is_less_equal */
T1 T6f15(TC* ac, T6 volatile* C, T6 a1)
{
	GE_call tc = {"INTEGER_32","is_less_equal",ac->call};
	T1 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((a1)<(*C)));
	R = ((T1)(!(t1)));
	ac->call = tc.caller;
	return R;
}

/* SPECIAL [BOOLEAN].make_filled */
T0* T67c4(TC* ac, T1 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","make_filled",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new67(ac, a2, EIF_TRUE);
	T67f6(ac, C, a2);
	t1 = ((T6)((a2)-((T6)(GE_int32(1)))));
	T67f7(ac, C, a1, (T6)(GE_int32(0)), t1);
	ac->call = tc.caller;
	return C;
}

/* SPECIAL [BOOLEAN].fill_with */
void T67f7(TC* ac, T0* C, T1 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","fill_with",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 t1;
	T1 t2;
	ac->call = &tc;
	l1 = a2;
	t1 = ((T6)((a3)+((T6)(GE_int32(1)))));
	l3 = (T6f12(ac, &(((T67*)(C))->a2), t1));
	l2 = l3;
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		((T67*)(C))->z2[l1] = (a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	l1 = l3;
	l2 = ((T6)((a3)+((T6)(GE_int32(1)))));
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		T67f9(ac, C, a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
}

/* SPECIAL [BOOLEAN].extend */
void T67f9(TC* ac, T0* C, T1 a1)
{
	GE_call tc = {"SPECIAL","extend",ac->call};
	T6 t1;
	ac->call = &tc;
	{
	t1 = ((T67*)(C))->a2;
	((T67*)(C))->a2 = t1 + 1;
	((T67*)(C))->z2[t1] = a1;
	}
	ac->call = tc.caller;
}

/* SPECIAL [BOOLEAN].make_empty */
void T67f6(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"SPECIAL","make_empty",ac->call};
	ac->call = &tc;
	{
	}
	ac->call = tc.caller;
}

/* SPECIAL [INTEGER_32].make_empty */
void T66f4(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"SPECIAL","make_empty",ac->call};
	ac->call = &tc;
	{
	}
	ac->call = tc.caller;
}

/* SPECIAL [INTEGER_32].make_empty */
T0* T66c4(TC* ac, T6 a1)
{
	GE_call tc = {"SPECIAL","make_empty",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new66(ac, a1, EIF_TRUE);
	{
	}
	ac->call = tc.caller;
	return C;
}

/* PRIMES.higher_prime */
T6 T65s1(TC* ac, T6 a1)
{
	GE_call tc = {"PRIMES","higher_prime",ac->call};
	T6 R = 0;
	T1 t1;
	T6 t2;
	ac->call = &tc;
	t1 = (T6f15(ac, &a1, (T6)(GE_int32(2))));
	if (t1) {
		R = (T6)(GE_int32(2));
	} else {
		t2 = ((T6)((a1)%((T6)(GE_int32(2)))));
		t1 = (T1)((t2) == ((T6)(GE_int32(0))));
		if (t1) {
			R = ((T6)((a1)+((T6)(GE_int32(1)))));
		} else {
			R = a1;
		}
		while (1) {
			t1 = (T65s3(ac, R));
			if (t1) {
				break;
			}
			R = ((T6)((R)+((T6)(GE_int32(2)))));
		}
	}
	ac->call = tc.caller;
	return R;
}

/* PRIMES.is_prime */
T1 T65s3(TC* ac, T6 a1)
{
	GE_call tc = {"PRIMES","is_prime",ac->call};
	T1 R = 0;
	T6 l1 = 0;
	T1 t1;
	T6 volatile t2;
	T6 volatile t3;
	ac->call = &tc;
	t1 = (T6f15(ac, &a1, (T6)(GE_int32(1))));
	if (t1) {
		R = EIF_FALSE;
	} else {
		t1 = (T1)((a1) == ((T6)(GE_int32(2))));
		if (t1) {
			R = EIF_TRUE;
		} else {
			t2 = ((T6)((a1)%((T6)(GE_int32(2)))));
			t1 = (T1)(!(T1)((t2) == ((T6)(GE_int32(0)))));
			if (t1) {
				l1 = (T6)(GE_int32(3));
				while (1) {
					t2 = ((T6)((a1)%(l1)));
					t1 = (T1)((t2) == ((T6)(GE_int32(0))));
					if (!(t1)) {
						t2 = ((T6)((l1)*(l1)));
						t1 = (T6f9(ac, &t2, a1));
					}
					if (t1) {
						break;
					}
					l1 = ((T6)((l1)+((T6)(GE_int32(2)))));
				}
				t3 = ((T6)((l1)*(l1)));
				t1 = (T6f14(ac, &t3, a1));
				if (t1) {
					R = EIF_TRUE;
				}
			}
		}
	}
	ac->call = tc.caller;
	return R;
}

/* PRIMES.default_create */
T0* T65c5(TC* ac)
{
	GE_call tc = {"PRIMES","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new65(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* DEVELOPER_EXCEPTION.exception_manager */
T0* T62s6(TC* ac)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* DEVELOPER_EXCEPTION.default_create */
T0* T62c11(TC* ac)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new62(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* EXCEPTIONS.default_create */
T0* T101c1(TC* ac)
{
	GE_call tc = {"EXCEPTIONS","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new101(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* MANAGED_POINTER.default_pointer */
T14 T73s4(TC* ac)
{
	T14 R = 0;
	return R;
}

/* POINTER.memory_realloc */
T14 T14f5(TC* ac, T14 volatile* C, T6 a1)
{
	GE_call tc = {"POINTER","memory_realloc",ac->call};
	T14 R = 0;
	ac->call = &tc;
	R = (T14s8(ac, *C, a1));
	ac->call = tc.caller;
	return R;
}

/* POINTER.c_realloc */
T14 T14s8(TC* ac, T14 a1, T6 a2)
{
	GE_call tc = {"POINTER","c_realloc",ac->call};
	T14 R = 0;
	ac->call = &tc;
	{
	R = (T14)(realloc((void *)(void*)a1,( size_t)a2));
	}
	ac->call = tc.caller;
	return R;
}

/* INTEGER_32.max */
T6 T6f4(TC* ac, T6 volatile* C, T6 a1)
{
	GE_call tc = {"INTEGER_32","max",ac->call};
	T6 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = (T6f9(ac, C, a1));
	if (t1) {
		R = *C;
	} else {
		R = a1;
	}
	ac->call = tc.caller;
	return R;
}

/* UTF_CONVERTER.utf_32_string_into_utf_8_0_pointer */
void T71s4(TC* ac, T0* a1, T0* a2, T6 a3, T0* a4)
{
	GE_call tc = {"UTF_CONVERTER","utf_32_string_into_utf_8_0_pointer",ac->call};
	T6 l1 = 0;
	T6 volatile l2 = 0;
	T6 l3 = 0;
	T6 l4 = 0;
	T10 volatile l5 = 0;
	T1 l6 = 0;
	T6 volatile t1;
	T6 t2;
	T1 t3;
	T8 t4;
	T10 volatile t5;
	T10 volatile t6;
	T10 volatile t7;
	T10 volatile t8;
	T10 volatile t9;
	T10 volatile t10;
	T10 volatile t11;
	T10 volatile t12;
	T10 volatile t13;
	ac->call = &tc;
	l3 = (((T17*)(a1))->a2);
	l4 = (((T73*)(a2))->a2);
	t1 = ((T6)((l4)-(a3)));
	t2 = ((T6)((l3)+((T6)(GE_int32(1)))));
	t3 = ((T1)((t1)<(t2)));
	if (t3) {
		t1 = (T71s3(ac, a1, (T6)(GE_int32(1)), l3));
		t1 = ((T6)((a3)+(t1)));
		l4 = ((T6)((t1)+((T6)(GE_int32(1)))));
		T73f8(ac, a2, l4);
		l6 = EIF_TRUE;
	}
	l2 = (T6)(GE_int32(0));
	l1 = a3;
	while (1) {
		t3 = (T6f9(ac, (&l2), l3));
		if (t3) {
			break;
		}
		l2 = ((T6)((l2)+((T6)(GE_int32(1)))));
		l5 = (T17f5(ac, a1, l2));
		t3 = (T10f5(ac, (&l5), (T10)(GE_nat32(127))));
		if (t3) {
			t4 = (T10f4(ac, (&l5)));
			T73f9(ac, a2, t4, l1);
			l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
		} else {
			t3 = ((T1)(!(l6)));
			if (t3) {
				t1 = ((T6)((l1)+((T6)(GE_int32(5)))));
				t2 = ((T6)((l3)-(l2)));
				t1 = ((T6)((t1)+(t2)));
				t3 = (T6f14(ac, &t1, l4));
			}
			if (t3) {
				t2 = (T71s3(ac, a1, l2, l3));
				t2 = ((T6)((l1)+(t2)));
				l4 = ((T6)((t2)+((T6)(GE_int32(1)))));
				T73f8(ac, a2, l4);
				l6 = EIF_TRUE;
			}
			t3 = (T10f5(ac, (&l5), (T10)(GE_nat32(2047))));
			if (t3) {
				t5 = ((T10)((l5)>>((T6)(GE_int32(6)))));
				t5 = ((T10)((t5)|((T10)(GE_nat32(192)))));
				t4 = (T10f4(ac, &t5));
				T73f9(ac, a2, t4, l1);
				t6 = ((T10)((l5)&((T10)(GE_nat32(63)))));
				t6 = ((T10)((t6)|((T10)(GE_nat32(128)))));
				t4 = (T10f4(ac, &t6));
				t2 = ((T6)((l1)+((T6)(GE_int32(1)))));
				T73f9(ac, a2, t4, t2);
				l1 = ((T6)((l1)+((T6)(GE_int32(2)))));
			} else {
				t3 = (T10f5(ac, (&l5), (T10)(GE_nat32(65535))));
				if (t3) {
					t7 = ((T10)((l5)>>((T6)(GE_int32(12)))));
					t7 = ((T10)((t7)|((T10)(GE_nat32(224)))));
					t4 = (T10f4(ac, &t7));
					T73f9(ac, a2, t4, l1);
					t8 = ((T10)((l5)>>((T6)(GE_int32(6)))));
					t8 = ((T10)((t8)&((T10)(GE_nat32(63)))));
					t8 = ((T10)((t8)|((T10)(GE_nat32(128)))));
					t4 = (T10f4(ac, &t8));
					t2 = ((T6)((l1)+((T6)(GE_int32(1)))));
					T73f9(ac, a2, t4, t2);
					t9 = ((T10)((l5)&((T10)(GE_nat32(63)))));
					t9 = ((T10)((t9)|((T10)(GE_nat32(128)))));
					t4 = (T10f4(ac, &t9));
					t2 = ((T6)((l1)+((T6)(GE_int32(2)))));
					T73f9(ac, a2, t4, t2);
					l1 = ((T6)((l1)+((T6)(GE_int32(3)))));
				} else {
					t10 = ((T10)((l5)>>((T6)(GE_int32(18)))));
					t10 = ((T10)((t10)|((T10)(GE_nat32(240)))));
					t4 = (T10f4(ac, &t10));
					T73f9(ac, a2, t4, l1);
					t11 = ((T10)((l5)>>((T6)(GE_int32(12)))));
					t11 = ((T10)((t11)&((T10)(GE_nat32(63)))));
					t11 = ((T10)((t11)|((T10)(GE_nat32(128)))));
					t4 = (T10f4(ac, &t11));
					t2 = ((T6)((l1)+((T6)(GE_int32(1)))));
					T73f9(ac, a2, t4, t2);
					t12 = ((T10)((l5)>>((T6)(GE_int32(6)))));
					t12 = ((T10)((t12)&((T10)(GE_nat32(63)))));
					t12 = ((T10)((t12)|((T10)(GE_nat32(128)))));
					t4 = (T10f4(ac, &t12));
					t2 = ((T6)((l1)+((T6)(GE_int32(2)))));
					T73f9(ac, a2, t4, t2);
					t13 = ((T10)((l5)&((T10)(GE_nat32(63)))));
					t13 = ((T10)((t13)|((T10)(GE_nat32(128)))));
					t4 = (T10f4(ac, &t13));
					t2 = ((T6)((l1)+((T6)(GE_int32(3)))));
					T73f9(ac, a2, t4, t2);
					l1 = ((T6)((l1)+((T6)(GE_int32(4)))));
				}
			}
		}
	}
	if (l6) {
		t2 = ((T6)((l1)+((T6)(GE_int32(1)))));
		T73f8(ac, a2, t2);
	}
	T73f9(ac, a2, (T8)(GE_nat8(0)), l1);
	t3 = (T1)(a4!=EIF_VOID);
	if (t3) {
		T72f2(ac, a4, l1);
	}
	ac->call = tc.caller;
}

/* MANAGED_POINTER.put_natural_8 */
void T73f9(TC* ac, T0* C, T8 a1, T6 a2)
{
	GE_call tc = {"MANAGED_POINTER","put_natural_8",ac->call};
	T14 volatile t1;
	T102 t2;
	T14 t3;
	ac->call = &tc;
	t1 = ((T14)(((char*)(((T73*)(C))->a1))+(a2)));
	(t2).a1 = ((T14)&a1);
	t3 = ((t2).a1);
	T14f13(ac, &t1, t3, (T6)(GE_int32(1)));
	ac->call = tc.caller;
}

/* POINTER.memory_copy */
void T14f13(TC* ac, T14 volatile* C, T14 a1, T6 a2)
{
	GE_call tc = {"POINTER","memory_copy",ac->call};
	ac->call = &tc;
	T14s17(ac, *C, a1, a2);
	ac->call = tc.caller;
}

/* POINTER.c_memcpy */
void T14s17(TC* ac, T14 a1, T14 a2, T6 a3)
{
	GE_call tc = {"POINTER","c_memcpy",ac->call};
	ac->call = &tc;
	{
	memcpy((void *)(void*)a1,( const void *)(void*)a2,( size_t)a3);
	}
	ac->call = tc.caller;
}

/* NATURAL_32.to_natural_8 */
T8 T10f4(TC* ac, T10 volatile* C)
{
	GE_call tc = {"NATURAL_32","to_natural_8",ac->call};
	T8 R = 0;
	ac->call = &tc;
	R = ((T8)(*C));
	ac->call = tc.caller;
	return R;
}

/* NATURAL_32.is_less_equal */
T1 T10f5(TC* ac, T10 volatile* C, T10 a1)
{
	GE_call tc = {"NATURAL_32","is_less_equal",ac->call};
	T1 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((a1)<(*C)));
	R = ((T1)(!(t1)));
	ac->call = tc.caller;
	return R;
}

/* STRING_8.code */
T10 T17f5(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"STRING_8","code",ac->call};
	T10 R = 0;
	T6 volatile t1;
	T2 t2;
	ac->call = &tc;
	t1 = ((T6)((a1)-((T6)(GE_int32(1)))));
	t2 = (((T15*)(((T17*)(C))->a1))->z2[t1]);
	t1 = ((T6)(t2));
	R = (T6f21(ac, &t1));
	ac->call = tc.caller;
	return R;
}

/* INTEGER_32.to_natural_32 */
T10 T6f21(TC* ac, T6 volatile* C)
{
	GE_call tc = {"INTEGER_32","to_natural_32",ac->call};
	T10 R = 0;
	ac->call = &tc;
	R = ((T10)(*C));
	ac->call = tc.caller;
	return R;
}

/* UTF_CONVERTER.utf_8_bytes_count */
T6 T71s3(TC* ac, T0* a1, T6 a2, T6 a3)
{
	GE_call tc = {"UTF_CONVERTER","utf_8_bytes_count",ac->call};
	T6 R = 0;
	T6 volatile l1 = 0;
	T10 volatile l2 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = a2;
	while (1) {
		t1 = (T6f14(ac, (&l1), a3));
		if (t1) {
			break;
		}
		l2 = (T17f5(ac, a1, l1));
		t1 = (T10f5(ac, (&l2), (T10)(GE_nat32(127))));
		if (t1) {
			R = ((T6)((R)+((T6)(GE_int32(1)))));
		} else {
			t1 = (T10f5(ac, (&l2), (T10)(GE_nat32(2047))));
			if (t1) {
				R = ((T6)((R)+((T6)(GE_int32(2)))));
			} else {
				t1 = (T10f5(ac, (&l2), (T10)(GE_nat32(65535))));
				if (t1) {
					R = ((T6)((R)+((T6)(GE_int32(3)))));
				} else {
					R = ((T6)((R)+((T6)(GE_int32(4)))));
				}
			}
		}
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
	return R;
}

/* CELL [INTEGER_32].put */
void T72f2(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"CELL","put",ac->call};
	ac->call = &tc;
	((T72*)(C))->a1 = a1;
	ac->call = tc.caller;
}

/* CELL [INTEGER_32].put */
T0* T72c2(TC* ac, T6 a1)
{
	GE_call tc = {"CELL","put",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new72(ac, EIF_TRUE);
	((T72*)(C))->a1 = a1;
	ac->call = tc.caller;
	return C;
}

/* C_STRING.make_empty */
void T31f4(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"C_STRING","make_empty",ac->call};
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T31*)(C))->a1 = T73c7(ac, t1);
	((T31*)(C))->a2 = (T6)(GE_int32(0));
	ac->call = tc.caller;
}

/* C_STRING.make_empty */
T0* T31c4(TC* ac, T6 a1)
{
	GE_call tc = {"C_STRING","make_empty",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new31(ac, EIF_TRUE);
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T31*)(C))->a1 = T73c7(ac, t1);
	((T31*)(C))->a2 = (T6)(GE_int32(0));
	ac->call = tc.caller;
	return C;
}

/* MANAGED_POINTER.make */
T0* T73c7(TC* ac, T6 a1)
{
	GE_call tc = {"MANAGED_POINTER","make",ac->call};
	T0* C;
	T6 t1;
	T14 t2;
	T1 t3;
	T0* t4;
	ac->call = &tc;
	C = GE_new73(ac, EIF_TRUE);
	T73f10(ac, C);
	t1 = (T6f4(ac, &a1, (T6)(GE_int32(1))));
	((T73*)(C))->a1 = (T14s4(ac, t1, (T6)(GE_int32(1))));
	t2 = (T73s4(ac));
	t3 = (T1)((((T73*)(C))->a1) == (t2));
	if (t3) {
		t4 = (T101c1(ac));
		T101s2(ac, GE_ms8("No more memory", 14));
	}
	((T73*)(C))->a2 = a1;
	((T73*)(C))->a3 = EIF_FALSE;
	ac->call = tc.caller;
	return C;
}

/* POINTER.memory_calloc */
T14 T14s4(TC* ac, T6 a1, T6 a2)
{
	GE_call tc = {"POINTER","memory_calloc",ac->call};
	T14 R = 0;
	ac->call = &tc;
	R = (T14s7(ac, a1, a2));
	ac->call = tc.caller;
	return R;
}

/* POINTER.c_calloc */
T14 T14s7(TC* ac, T6 a1, T6 a2)
{
	GE_call tc = {"POINTER","c_calloc",ac->call};
	T14 R = 0;
	ac->call = &tc;
	{
	R = (T14)(calloc((size_t)a1,( size_t)a2));
	}
	ac->call = tc.caller;
	return R;
}

/* MANAGED_POINTER.increment_counter */
void T73f10(TC* ac, T0* C)
{
	GE_call tc = {"MANAGED_POINTER","increment_counter",ac->call};
	ac->call = &tc;
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.set_description */
void T64f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"SERIALIZATION_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T64*)(C))->a1 = l3;
	} else {
		((T64*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* OLD_VIOLATION.set_description */
void T37f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OLD_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T37*)(C))->a1 = l3;
	} else {
		((T37*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* COM_FAILURE.set_description */
void T44f22(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T44*)(C))->a1 = l3;
	} else {
		((T44*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_description */
void T63f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T63*)(C))->a1 = l3;
	} else {
		((T63*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.set_description */
void T62f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T62*)(C))->a1 = l3;
	} else {
		((T62*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* MISMATCH_FAILURE.set_description */
void T61f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"MISMATCH_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T61*)(C))->a1 = l3;
	} else {
		((T61*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_description */
void T43f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T43*)(C))->a1 = l3;
	} else {
		((T43*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* IO_FAILURE.set_description */
void T42f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"IO_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T42*)(C))->a1 = l3;
	} else {
		((T42*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_description */
void T60f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T60*)(C))->a1 = l3;
	} else {
		((T60*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* VOID_ASSIGNED_TO_EXPANDED.set_description */
void T59f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T59*)(C))->a1 = l3;
	} else {
		((T59*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* EXTERNAL_FAILURE.set_description */
void T58f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXTERNAL_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T58*)(C))->a1 = l3;
	} else {
		((T58*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* CREATE_ON_DEFERRED.set_description */
void T57f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CREATE_ON_DEFERRED","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T57*)(C))->a1 = l3;
	} else {
		((T57*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* RESUMPTION_FAILURE.set_description */
void T56f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESUMPTION_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T56*)(C))->a1 = l3;
	} else {
		((T56*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* RESCUE_FAILURE.set_description */
void T55f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESCUE_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T55*)(C))->a1 = l3;
	} else {
		((T55*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.set_description */
void T45f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T45*)(C))->a1 = l3;
	} else {
		((T45*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_description */
void T41f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T41*)(C))->a1 = l3;
	} else {
		((T41*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* LOOP_INVARIANT_VIOLATION.set_description */
void T54f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T54*)(C))->a1 = l3;
	} else {
		((T54*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* VARIANT_VIOLATION.set_description */
void T53f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VARIANT_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T53*)(C))->a1 = l3;
	} else {
		((T53*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* BAD_INSPECT_VALUE.set_description */
void T52f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"BAD_INSPECT_VALUE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T52*)(C))->a1 = l3;
	} else {
		((T52*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_description */
void T35f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T35*)(C))->a1 = l3;
	} else {
		((T35*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* CHECK_VIOLATION.set_description */
void T51f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CHECK_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T51*)(C))->a1 = l3;
	} else {
		((T51*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_description */
void T40f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T40*)(C))->a1 = l3;
	} else {
		((T40*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* FLOATING_POINT_FAILURE.set_description */
void T50f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T50*)(C))->a1 = l3;
	} else {
		((T50*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* POSTCONDITION_VIOLATION.set_description */
void T49f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T49*)(C))->a1 = l3;
	} else {
		((T49*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* PRECONDITION_VIOLATION.set_description */
void T48f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"PRECONDITION_VIOLATION","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T48*)(C))->a1 = l3;
	} else {
		((T48*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* VOID_TARGET.set_description */
void T33f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_TARGET","set_description",ac->call};
	T71 l1 = GE_default71;
	T0* l2 = 0;
	T0* l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	t1 = (T1)(a1!=EIF_VOID);
	if (t1) {
		t2 = (((T17*)(a1))->a2);
		l3 = T31c4(ac, t2);
		l2 = T72c2(ac, (T6)(GE_int32(0)));
		t3 = (((T31*)(l3))->a1);
		T71s4(ac, a1, t3, (T6)(GE_int32(0)), l2);
		t2 = (((T72*)(l2))->a1);
		T31f5(ac, l3, t2);
		((T33*)(C))->a1 = l3;
	} else {
		((T33*)(C))->a1 = EIF_VOID;
	}
	ac->call = tc.caller;
}

/* ISE_EXCEPTION_MANAGER.in_rescue */
T1 T21s8(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","in_rescue",ac->call};
	T1 R = 0;
	ac->call = &tc;
	{
	R = EIF_TEST(eif_is_in_rescue());
	}
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.set_exception_information */
void T44f20(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_exception_information",ac->call};
	T0* l1 = 0;
	T1 t1;
	T0* t2;
	T14 t3;
	ac->call = &tc;
	((T44*)(C))->a4 = a1;
	t1 = (T6f14(ac, &(((T44*)(C))->a3), (T6)(GE_int32(0))));
	if (t1) {
		t2 = (T44f10(ac, C, ((T44*)(C))->a3));
		l1 = T31c6(ac, t2);
		t3 = (T31f3(ac, l1));
		((T44*)(C))->a5 = ((T6)GE_ccom_hresult(t3));
	} else {
		l1 = T31c6(ac, a1);
		t3 = (T31f3(ac, l1));
		((T44*)(C))->a5 = ((T6)GE_ccom_hresult(t3));
		((T44*)(C))->a3 = ((T6)GE_ccom_hresult_code(((T44*)(C))->a5));
	}
	ac->call = tc.caller;
}

/* C_STRING.make */
T0* T31c6(TC* ac, T0* a1)
{
	GE_call tc = {"C_STRING","make",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new31(ac, EIF_TRUE);
	t1 = (((T17*)(a1))->a2);
	T31f4(ac, C, t1);
	T31f7(ac, C, a1);
	ac->call = tc.caller;
	return C;
}

/* C_STRING.set_string */
void T31f7(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"C_STRING","set_string",ac->call};
	T6 t1;
	ac->call = &tc;
	t1 = (((T17*)(a1))->a2);
	T31f8(ac, C, a1, (T6)(GE_int32(1)), t1);
	ac->call = tc.caller;
}

/* C_STRING.set_substring */
void T31f8(TC* ac, T0* C, T0* a1, T6 a2, T6 a3)
{
	GE_call tc = {"C_STRING","set_substring",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 t1;
	T1 t2;
	T10 volatile t3;
	T8 t4;
	ac->call = &tc;
	t1 = ((T6)((a3)-(a2)));
	l2 = ((T6)((t1)+((T6)(GE_int32(1)))));
	((T31*)(C))->a2 = l2;
	l3 = ((T6)((l2)+((T6)(GE_int32(1)))));
	t1 = (((T73*)(((T31*)(C))->a1))->a2);
	t2 = ((T1)((t1)<(l3)));
	if (t2) {
		T73f8(ac, ((T31*)(C))->a1, l3);
	}
	l1 = (T6)(GE_int32(0));
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		t1 = ((T6)((l1)+(a2)));
		t3 = (T17f5(ac, a1, t1));
		t4 = (T10f4(ac, &t3));
		T73f9(ac, ((T31*)(C))->a1, t4, l1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	T73f9(ac, ((T31*)(C))->a1, (T8)(GE_nat8(0)), l2);
	ac->call = tc.caller;
}

/* COM_FAILURE.ccom_hresult_to_string */
T0* T44f10(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"COM_FAILURE","ccom_hresult_to_string",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = (T6f18(ac, &a1));
	R = (T17f6(ac, GE_ms8("0x", 2), R));
	ac->call = tc.caller;
	return R;
}

/* STRING_8.plus */
T0* T17f6(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"STRING_8","plus",ac->call};
	T0* R = 0;
	T6 t1;
	ac->call = &tc;
	t1 = (((T17*)(a1))->a2);
	t1 = ((T6)((((T17*)(C))->a2)+(t1)));
	R = (T17f7(ac, C, t1));
	T17f15(ac, R, C);
	T17f15(ac, R, a1);
	ac->call = tc.caller;
	return R;
}

/* STRING_8.append */
void T17f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"STRING_8","append",ac->call};
	T6 l1 = 0;
	T6 volatile l2 = 0;
	T6 volatile l3 = 0;
	T1 t1;
	T6 t2;
	T0* t3;
	ac->call = &tc;
	l2 = (((T17*)(a1))->a2);
	t1 = (T6f14(ac, (&l2), (T6)(GE_int32(0))));
	if (t1) {
		l1 = ((T17*)(C))->a2;
		l3 = ((T6)((l2)+(l1)));
		t2 = (T17f8(ac, C));
		t1 = (T6f14(ac, (&l3), t2));
		if (t1) {
			t2 = (T17f9(ac, C));
			t2 = ((T6)((l3)+(t2)));
			T17f18(ac, C, t2);
		}
		t3 = (((T17*)(a1))->a1);
		t2 = (T17f10(ac, a1));
		T15f11(ac, ((T17*)(C))->a1, t3, t2, l1, l2);
		((T17*)(C))->a2 = l3;
		T17f17(ac, C);
	}
	ac->call = tc.caller;
}

/* STRING_8.reset_hash_codes */
void T17f17(TC* ac, T0* C)
{
	GE_call tc = {"STRING_8","reset_hash_codes",ac->call};
	ac->call = &tc;
	((T17*)(C))->a3 = (T6)(GE_int32(0));
	((T17*)(C))->a4 = (T6)(GE_int32(0));
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].copy_data */
void T15f11(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4)
{
	GE_call tc = {"SPECIAL","copy_data",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T1 t1;
	T2 t2;
	ac->call = &tc;
	t1 = (T1)(a1==C);
	if (t1) {
		T15f12(ac, C, a2, a3, a4);
	} else {
		l1 = a2;
		l2 = a3;
		l3 = ((T6)((a2)+(a4)));
		while (1) {
			t1 = (T1)((l1) == (l3));
			if (t1) {
				break;
			}
			t2 = (((T15*)(a1))->z2[l1]);
			T15f13(ac, C, t2, l2);
			l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
			l2 = ((T6)((l2)+((T6)(GE_int32(1)))));
		}
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].force */
void T15f13(TC* ac, T0* C, T2 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","force",ac->call};
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((a2)<(((T15*)(C))->a2)));
	if (t1) {
		((T15*)(C))->z2[a2] = (a1);
	} else {
		T15f10(ac, C, a1);
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].extend */
void T15f10(TC* ac, T0* C, T2 a1)
{
	GE_call tc = {"SPECIAL","extend",ac->call};
	T6 t1;
	ac->call = &tc;
	{
	t1 = ((T15*)(C))->a2;
	((T15*)(C))->a2 = t1 + 1;
	((T15*)(C))->z2[t1] = a1;
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].move_data */
void T15f12(TC* ac, T0* C, T6 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","move_data",ac->call};
	T1 t1;
	T6 t2;
	ac->call = &tc;
	t1 = (T1)((a1) == (a2));
	if (t1) {
	} else {
		t1 = (T6f14(ac, &a1, a2));
		if (t1) {
			t2 = ((T6)((a2)+(a3)));
			t1 = ((T1)((t2)<(a1)));
			if (t1) {
				T15f14(ac, C, a1, a2, a3);
			} else {
				T15f15(ac, C, a1, a2, a3);
			}
		} else {
			t2 = ((T6)((a1)+(a3)));
			t1 = ((T1)((t2)<(a2)));
			if (t1) {
				T15f14(ac, C, a1, a2, a3);
			} else {
				T15f15(ac, C, a1, a2, a3);
			}
		}
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].overlapping_move */
void T15f15(TC* ac, T0* C, T6 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","overlapping_move",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T1 t1;
	T6 volatile t2;
	T2 t3;
	T6 t4;
	ac->call = &tc;
	t1 = ((T1)((a1)<(a2)));
	if (t1) {
		t2 = ((T6)((a1)+(a3)));
		l1 = ((T6)((t2)-((T6)(GE_int32(1)))));
		l2 = ((T6)((a1)-((T6)(GE_int32(1)))));
		l3 = ((T6)((a2)-(a1)));
		t2 = ((T6)((a2)+(a3)));
		t1 = (T6f9(ac, &t2, ((T15*)(C))->a2));
		if (t1) {
			t3 = (((T15*)(C))->z2[a1]);
			t4 = ((T6)((a2)+(a3)));
			t4 = ((T6)((t4)-((T6)(GE_int32(1)))));
			T15f8(ac, C, t3, ((T15*)(C))->a2, t4);
		}
		while (1) {
			t1 = (T1)((l1) == (l2));
			if (t1) {
				break;
			}
			t3 = (((T15*)(C))->z2[l1]);
			t4 = ((T6)((l1)+(l3)));
			((T15*)(C))->z2[t4] = (t3);
			l1 = ((T6)((l1)-((T6)(GE_int32(1)))));
		}
	} else {
		l1 = a1;
		l2 = ((T6)((a1)+(a3)));
		l3 = ((T6)((a1)-(a2)));
		while (1) {
			t1 = (T1)((l1) == (l2));
			if (t1) {
				break;
			}
			t3 = (((T15*)(C))->z2[l1]);
			t4 = ((T6)((l1)-(l3)));
			T15f13(ac, C, t3, t4);
			l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
		}
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].fill_with */
void T15f8(TC* ac, T0* C, T2 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","fill_with",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 t1;
	T1 t2;
	ac->call = &tc;
	l1 = a2;
	t1 = ((T6)((a3)+((T6)(GE_int32(1)))));
	l3 = (T6f12(ac, &(((T15*)(C))->a2), t1));
	l2 = l3;
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		((T15*)(C))->z2[l1] = (a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	l1 = l3;
	l2 = ((T6)((a3)+((T6)(GE_int32(1)))));
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		T15f10(ac, C, a1);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].non_overlapping_move */
void T15f14(TC* ac, T0* C, T6 a1, T6 a2, T6 a3)
{
	GE_call tc = {"SPECIAL","non_overlapping_move",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T1 t1;
	T2 t2;
	T6 t3;
	ac->call = &tc;
	l1 = a1;
	l2 = ((T6)((a1)+(a3)));
	l3 = ((T6)((a2)-(a1)));
	while (1) {
		t1 = (T1)((l1) == (l2));
		if (t1) {
			break;
		}
		t2 = (((T15*)(C))->z2[l1]);
		t3 = ((T6)((l1)+(l3)));
		T15f13(ac, C, t2, t3);
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
}

/* STRING_8.area_lower */
T6 T17f10(TC* ac, T0* C)
{
	T6 R = 0;
	return R;
}

/* STRING_8.resize */
void T17f18(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"STRING_8","resize",ac->call};
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T17*)(C))->a1 = (T15f4(ac, ((T17*)(C))->a1, (T2)('\000'), t1));
	ac->call = tc.caller;
}

/* SPECIAL [CHARACTER_8].aliased_resized_area_with_default */
T0* T15f4(TC* ac, T0* C, T2 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","aliased_resized_area_with_default",ac->call};
	T0* R = 0;
	T6 t1;
	T6 t2;
	ac->call = &tc;
	R = (T15f5(ac, C, a2));
	t1 = (((T15*)(R))->a2);
	t2 = ((T6)((a2)-((T6)(GE_int32(1)))));
	T15f8(ac, R, a1, t1, t2);
	ac->call = tc.caller;
	return R;
}

/* SPECIAL [CHARACTER_8].aliased_resized_area */
T0* T15f5(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"SPECIAL","aliased_resized_area",ac->call};
	T0* R = 0;
	T6 t1;
	T6 t2;
	ac->call = &tc;
	{
	t1 = ((T15*)(C))->a1;
	if (a1 == t1) {
		R = C;
	} else {
		R = GE_new15(ac, a1, EIF_TRUE);
		t1 = ((T15*)(C))->a2;
		((T15*)(R))->a2 = ((t1 < a1)?t1:a1);
		t2 = ((T15*)(C))->a2;
		t1 = ((T15*)(R))->a2;
		if (t2 > t1) {
			t2 = t1;
		}
		if (t2 > 0) {
			memcpy((void*)(((T15*)(R))->z2), (void*)(((T15*)(C))->z2), t2 * sizeof(T2));
		}
	}
	}
	ac->call = tc.caller;
	return R;
}

/* STRING_8.additional_space */
T6 T17f9(TC* ac, T0* C)
{
	GE_call tc = {"STRING_8","additional_space",ac->call};
	T6 R = 0;
	T6 volatile t1;
	ac->call = &tc;
	t1 = (T17f8(ac, C));
	t1 = ((T6)((t1)/((T6)(GE_int32(2)))));
	R = (T6f4(ac, &t1, (T6)(GE_int32(5))));
	ac->call = tc.caller;
	return R;
}

/* STRING_8.capacity */
T6 T17f8(TC* ac, T0* C)
{
	GE_call tc = {"STRING_8","capacity",ac->call};
	T6 R = 0;
	T6 t1;
	ac->call = &tc;
	t1 = (((T15*)(((T17*)(C))->a1))->a2);
	R = ((T6)((t1)-((T6)(GE_int32(1)))));
	ac->call = tc.caller;
	return R;
}

/* STRING_8.new_string */
T0* T17f7(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"STRING_8","new_string",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = T17c12(ac, a1);
	ac->call = tc.caller;
	return R;
}

/* STRING_8.make */
void T17f12(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"STRING_8","make",ac->call};
	T6 t1;
	ac->call = &tc;
	((T17*)(C))->a2 = (T6)(GE_int32(0));
	((T17*)(C))->a3 = (T6)(GE_int32(0));
	((T17*)(C))->a4 = (T6)(GE_int32(0));
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T17*)(C))->a1 = T15c6(ac, (T2)('\000'), t1);
	ac->call = tc.caller;
}

/* STRING_8.make */
T0* T17c12(TC* ac, T6 a1)
{
	GE_call tc = {"STRING_8","make",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new17(ac, EIF_TRUE);
	((T17*)(C))->a2 = (T6)(GE_int32(0));
	((T17*)(C))->a3 = (T6)(GE_int32(0));
	((T17*)(C))->a4 = (T6)(GE_int32(0));
	t1 = ((T6)((a1)+((T6)(GE_int32(1)))));
	((T17*)(C))->a1 = T15c6(ac, (T2)('\000'), t1);
	ac->call = tc.caller;
	return C;
}

/* SPECIAL [CHARACTER_8].make_filled */
T0* T15c6(TC* ac, T2 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","make_filled",ac->call};
	T0* C;
	T6 t1;
	ac->call = &tc;
	C = GE_new15(ac, a2, EIF_TRUE);
	T15f7(ac, C, a2);
	t1 = ((T6)((a2)-((T6)(GE_int32(1)))));
	T15f8(ac, C, a1, (T6)(GE_int32(0)), t1);
	ac->call = tc.caller;
	return C;
}

/* SPECIAL [CHARACTER_8].make_empty */
void T15f7(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"SPECIAL","make_empty",ac->call};
	ac->call = &tc;
	{
	}
	ac->call = tc.caller;
}

/* INTEGER_32.to_hex_string */
T0* T6f18(TC* ac, T6 volatile* C)
{
	GE_call tc = {"INTEGER_32","to_hex_string",ac->call};
	T0* R = 0;
	T6 l1 = 0;
	T6 l2 = 0;
	T6 volatile t1;
	T1 t2;
	T2 t3;
	ac->call = &tc;
	t1 = (T6)(GE_int32(32));
	l1 = ((T6)((t1)/((T6)(GE_int32(4)))));
	R = T17c13(ac, (T2)('0'), l1);
	l2 = *C;
	while (1) {
		t2 = (T1)((l1) == ((T6)(GE_int32(0))));
		if (t2) {
			break;
		}
		t1 = ((T6)((l2)&((T6)(GE_int32(15)))));
		t3 = (T6f19(ac, &t1));
		T17f14(ac, R, t3, l1);
		l2 = ((T6)((l2)>>((T6)(GE_int32(4)))));
		l1 = ((T6)((l1)-((T6)(GE_int32(1)))));
	}
	ac->call = tc.caller;
	return R;
}

/* STRING_8.put */
void T17f14(TC* ac, T0* C, T2 a1, T6 a2)
{
	GE_call tc = {"STRING_8","put",ac->call};
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)((a2)-((T6)(GE_int32(1)))));
	((T15*)(((T17*)(C))->a1))->z2[t1] = (a1);
	T17f17(ac, C);
	ac->call = tc.caller;
}

/* INTEGER_32.to_hex_character */
T2 T6f19(TC* ac, T6 volatile* C)
{
	GE_call tc = {"INTEGER_32","to_hex_character",ac->call};
	T2 R = 0;
	T6 volatile l1 = 0;
	T2 volatile t1;
	T1 t2;
	T2 volatile t3;
	ac->call = &tc;
	l1 = *C;
	t2 = (T6f15(ac, (&l1), (T6)(GE_int32(9))));
	if (t2) {
		t1 = (T2)('0');
	} else {
		t3 = (T2)('A');
		t1 = (T2f4(ac, &t3, (T6)(GE_int32(10))));
	}
	R = (T2f5(ac, &t1, l1));
	ac->call = tc.caller;
	return R;
}

/* CHARACTER_8.plus */
T2 T2f5(TC* ac, T2 volatile* C, T6 a1)
{
	GE_call tc = {"CHARACTER_8","plus",ac->call};
	T2 R = 0;
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)(*C));
	t1 = ((T6)((t1)+(a1)));
	R = ((T2)(t1));
	ac->call = tc.caller;
	return R;
}

/* CHARACTER_8.minus */
T2 T2f4(TC* ac, T2 volatile* C, T6 a1)
{
	GE_call tc = {"CHARACTER_8","minus",ac->call};
	T2 R = 0;
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)(*C));
	t1 = ((T6)((t1)-(a1)));
	R = ((T2)(t1));
	ac->call = tc.caller;
	return R;
}

/* STRING_8.make_filled */
T0* T17c13(TC* ac, T2 a1, T6 a2)
{
	GE_call tc = {"STRING_8","make_filled",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new17(ac, EIF_TRUE);
	T17f12(ac, C, a2);
	T17f16(ac, C, a1);
	ac->call = tc.caller;
	return C;
}

/* STRING_8.fill_character */
void T17f16(TC* ac, T0* C, T2 a1)
{
	GE_call tc = {"STRING_8","fill_character",ac->call};
	T6 l1 = 0;
	T1 t1;
	T6 t2;
	ac->call = &tc;
	l1 = (T17f8(ac, C));
	t1 = (T1)(!(T1)((l1) == ((T6)(GE_int32(0)))));
	if (t1) {
		t2 = ((T6)((l1)-((T6)(GE_int32(1)))));
		T15f8(ac, ((T17*)(C))->a1, a1, (T6)(GE_int32(0)), t2);
		((T17*)(C))->a2 = l1;
		((T17*)(C))->a3 = (T6)(GE_int32(0));
		((T17*)(C))->a4 = (T6)(GE_int32(0));
	}
	ac->call = tc.caller;
}

/* COM_FAILURE.set_hresult_code */
void T44f19(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"COM_FAILURE","set_hresult_code",ac->call};
	ac->call = &tc;
	((T44*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_error_code */
void T43f14(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_error_code",ac->call};
	ac->call = &tc;
	((T43*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.set_error_code */
void T42f16(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"IO_FAILURE","set_error_code",ac->call};
	ac->call = &tc;
	((T42*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_signal_code */
void T41f14(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_signal_code",ac->call};
	ac->call = &tc;
	((T41*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_is_entry */
void T40f14(TC* ac, T0* C, T1 a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_is_entry",ac->call};
	ac->call = &tc;
	((T40*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_class_name */
void T35f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_class_name",ac->call};
	ac->call = &tc;
	((T35*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_routine_name */
void T35f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_routine_name",ac->call};
	ac->call = &tc;
	((T35*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* NO_MORE_MEMORY.set_throwing_exception */
void T39f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T39*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.set_throwing_exception */
void T64f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"SERIALIZATION_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T64*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* OLD_VIOLATION.set_throwing_exception */
void T37f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OLD_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T37*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* COM_FAILURE.set_throwing_exception */
void T44f18(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"COM_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T44*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_throwing_exception */
void T63f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T63*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* DEVELOPER_EXCEPTION.set_throwing_exception */
void T62f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T62*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* MISMATCH_FAILURE.set_throwing_exception */
void T61f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"MISMATCH_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T61*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_FAILURE.set_throwing_exception */
void T43f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T43*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.set_throwing_exception */
void T42f15(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"IO_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T42*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_throwing_exception */
void T60f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T60*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* VOID_ASSIGNED_TO_EXPANDED.set_throwing_exception */
void T59f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T59*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* EXTERNAL_FAILURE.set_throwing_exception */
void T58f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EXTERNAL_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T58*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* CREATE_ON_DEFERRED.set_throwing_exception */
void T57f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CREATE_ON_DEFERRED","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T57*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* RESUMPTION_FAILURE.set_throwing_exception */
void T56f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESUMPTION_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T56*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* RESCUE_FAILURE.set_throwing_exception */
void T55f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"RESCUE_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T55*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.set_throwing_exception */
void T45f14(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T45*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_throwing_exception */
void T41f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T41*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* LOOP_INVARIANT_VIOLATION.set_throwing_exception */
void T54f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T54*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* VARIANT_VIOLATION.set_throwing_exception */
void T53f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VARIANT_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T53*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* BAD_INSPECT_VALUE.set_throwing_exception */
void T52f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"BAD_INSPECT_VALUE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T52*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* ROUTINE_FAILURE.set_throwing_exception */
void T35f16(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"ROUTINE_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T35*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* CHECK_VIOLATION.set_throwing_exception */
void T51f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CHECK_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T51*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* INVARIANT_VIOLATION.set_throwing_exception */
void T40f13(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"INVARIANT_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T40*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* FLOATING_POINT_FAILURE.set_throwing_exception */
void T50f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T50*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* POSTCONDITION_VIOLATION.set_throwing_exception */
void T49f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T49*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* PRECONDITION_VIOLATION.set_throwing_exception */
void T48f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"PRECONDITION_VIOLATION","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T48*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* VOID_TARGET.set_throwing_exception */
void T33f12(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"VOID_TARGET","set_throwing_exception",ac->call};
	ac->call = &tc;
	((T33*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* ISE_EXCEPTION_MANAGER.exception_from_code */
T0* T21s12(TC* ac, T6 a1)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","exception_from_code",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T0* l2 = 0;
	T0* l3 = 0;
	T0* t1;
	ac->call = &tc;
	switch (a1) {
	case GE_int32(1):
		R = T33c11(ac);
		break;
	case GE_int32(2):
		t1 = (T21s7(ac));
		l3 = (((T30*)(t1))->a1);
		T39f14(ac, l3, (T6)(GE_int32(2)));
		R = l3;
		break;
	case GE_int32(3):
		R = T48c11(ac);
		break;
	case GE_int32(4):
		R = T49c11(ac);
		break;
	case GE_int32(5):
		R = T50c11(ac);
		break;
	case GE_int32(6):
		R = T40c12(ac);
		break;
	case GE_int32(7):
		R = T51c11(ac);
		break;
	case GE_int32(8):
		R = T35c13(ac);
		break;
	case GE_int32(9):
		R = T52c11(ac);
		break;
	case GE_int32(10):
		R = T53c11(ac);
		break;
	case GE_int32(11):
		R = T54c11(ac);
		break;
	case GE_int32(12):
		R = T41c12(ac);
		break;
	case GE_int32(13):
		l1 = T45c12(ac);
		T45f13(ac, l1, (T6)(GE_int32(13)));
		R = l1;
		break;
	case GE_int32(14):
		R = T55c11(ac);
		break;
	case GE_int32(15):
		t1 = (T21s7(ac));
		l3 = (((T30*)(t1))->a1);
		T39f14(ac, l3, (T6)(GE_int32(15)));
		R = l3;
		break;
	case GE_int32(16):
		R = T56c11(ac);
		break;
	case GE_int32(17):
		R = T57c11(ac);
		break;
	case GE_int32(18):
		R = T58c11(ac);
		break;
	case GE_int32(19):
		R = T59c11(ac);
		break;
	case GE_int32(20):
		R = T60c11(ac);
		break;
	case GE_int32(21):
		l2 = T42c13(ac);
		T42f14(ac, l2, (T6)(GE_int32(21)));
		R = l2;
		break;
	case GE_int32(22):
		R = T43c12(ac);
		break;
	case GE_int32(23):
		R = T61c11(ac);
		break;
	case GE_int32(24):
		R = T62c11(ac);
		break;
	case GE_int32(25):
		l1 = T45c12(ac);
		T45f13(ac, l1, (T6)(GE_int32(25)));
		R = l1;
		break;
	case GE_int32(26):
		R = T63c11(ac);
		break;
	case GE_int32(27):
		l2 = T42c13(ac);
		T42f14(ac, l2, (T6)(GE_int32(27)));
		R = l2;
		break;
	case GE_int32(28):
		R = T44c17(ac);
		break;
	case GE_int32(29):
		R = T51c11(ac);
		break;
	case GE_int32(30):
		R = T37c11(ac);
		break;
	case GE_int32(31):
		R = T64c11(ac);
		break;
	default:
		break;
	}
	ac->call = tc.caller;
	return R;
}

/* SERIALIZATION_FAILURE.default_create */
T0* T64c11(TC* ac)
{
	GE_call tc = {"SERIALIZATION_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new64(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* OLD_VIOLATION.default_create */
T0* T37c11(TC* ac)
{
	GE_call tc = {"OLD_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new37(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* COM_FAILURE.default_create */
T0* T44c17(TC* ac)
{
	GE_call tc = {"COM_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new44(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.default_create */
T0* T63c11(TC* ac)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new63(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* MISMATCH_FAILURE.default_create */
T0* T61c11(TC* ac)
{
	GE_call tc = {"MISMATCH_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new61(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* OPERATING_SYSTEM_FAILURE.default_create */
T0* T43c12(TC* ac)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new43(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* IO_FAILURE.set_code */
void T42f14(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"IO_FAILURE","set_code",ac->call};
	ac->call = &tc;
	((T42*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* IO_FAILURE.default_create */
T0* T42c13(TC* ac)
{
	GE_call tc = {"IO_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new42(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.default_create */
T0* T60c11(TC* ac)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new60(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* VOID_ASSIGNED_TO_EXPANDED.default_create */
T0* T59c11(TC* ac)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new59(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* EXTERNAL_FAILURE.default_create */
T0* T58c11(TC* ac)
{
	GE_call tc = {"EXTERNAL_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new58(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* CREATE_ON_DEFERRED.default_create */
T0* T57c11(TC* ac)
{
	GE_call tc = {"CREATE_ON_DEFERRED","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new57(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* RESUMPTION_FAILURE.default_create */
T0* T56c11(TC* ac)
{
	GE_call tc = {"RESUMPTION_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new56(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* RESCUE_FAILURE.default_create */
T0* T55c11(TC* ac)
{
	GE_call tc = {"RESCUE_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new55(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* EIFFEL_RUNTIME_PANIC.set_code */
void T45f13(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","set_code",ac->call};
	ac->call = &tc;
	((T45*)(C))->a3 = (T45f9(ac, C));
	ac->call = tc.caller;
}

/* EIFFEL_RUNTIME_PANIC.code */
T6 T45f9(TC* ac, T0* C)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","code",ac->call};
	T6 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = (T1)((((T45*)(C))->a3) == ((T6)(GE_int32(25))));
	if (t1) {
		R = ((T45*)(C))->a3;
	} else {
		R = (T6)(GE_int32(13));
	}
	ac->call = tc.caller;
	return R;
}

/* EIFFEL_RUNTIME_PANIC.default_create */
T0* T45c12(TC* ac)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new45(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.default_create */
T0* T41c12(TC* ac)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new41(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* LOOP_INVARIANT_VIOLATION.default_create */
T0* T54c11(TC* ac)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new54(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* VARIANT_VIOLATION.default_create */
T0* T53c11(TC* ac)
{
	GE_call tc = {"VARIANT_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new53(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* BAD_INSPECT_VALUE.default_create */
T0* T52c11(TC* ac)
{
	GE_call tc = {"BAD_INSPECT_VALUE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new52(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* ROUTINE_FAILURE.default_create */
T0* T35c13(TC* ac)
{
	GE_call tc = {"ROUTINE_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new35(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* CHECK_VIOLATION.default_create */
T0* T51c11(TC* ac)
{
	GE_call tc = {"CHECK_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new51(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* INVARIANT_VIOLATION.default_create */
T0* T40c12(TC* ac)
{
	GE_call tc = {"INVARIANT_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new40(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* FLOATING_POINT_FAILURE.default_create */
T0* T50c11(TC* ac)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new50(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* POSTCONDITION_VIOLATION.default_create */
T0* T49c11(TC* ac)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new49(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* PRECONDITION_VIOLATION.default_create */
T0* T48c11(TC* ac)
{
	GE_call tc = {"PRECONDITION_VIOLATION","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new48(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* NO_MORE_MEMORY.set_code */
void T39f14(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"NO_MORE_MEMORY","set_code",ac->call};
	ac->call = &tc;
	((T39*)(C))->a3 = (T39f9(ac, C));
	ac->call = tc.caller;
}

/* NO_MORE_MEMORY.code */
T6 T39f9(TC* ac, T0* C)
{
	GE_call tc = {"NO_MORE_MEMORY","code",ac->call};
	T6 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = (T1)((((T39*)(C))->a3) == ((T6)(GE_int32(15))));
	if (t1) {
		R = ((T39*)(C))->a3;
	} else {
		R = (T6)(GE_int32(2));
	}
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.no_memory_exception_object_cell */
T0* T21s7(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","no_memory_exception_object_cell",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	T0* l1 = 0;
	T0* t1;
	if (GE_process_onces->reference_status[2]) {
		if (GE_process_onces->reference_exception[2]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[2]);
		}
		return GE_process_onces->reference_value[2];
	} else {
		GE_process_onces->reference_status[2] = '\1';
		GE_process_onces->reference_value[2] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[2] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	l1 = T39c12(ac);
	t1 = (T17c12(ac, (T6)(GE_int32(4096))));
	T39f13(ac, l1, t1);
	R = T30c2(ac, l1);
	GE_process_onces->reference_value[2] = R;
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* CELL [NO_MORE_MEMORY].put */
T0* T30c2(TC* ac, T0* a1)
{
	GE_call tc = {"CELL","put",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new30(ac, EIF_TRUE);
	((T30*)(C))->a1 = a1;
	ac->call = tc.caller;
	return C;
}

/* NO_MORE_MEMORY.default_create */
T0* T39c12(TC* ac)
{
	GE_call tc = {"NO_MORE_MEMORY","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new39(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* VOID_TARGET.default_create */
T0* T33c11(TC* ac)
{
	GE_call tc = {"VOID_TARGET","default_create",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new33(ac, EIF_TRUE);
	ac->call = tc.caller;
	return C;
}

/* ISE_EXCEPTION_MANAGER.exception_data */
T0* T21s11(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","exception_data",ac->call};
	T0* R = 0;
	T0* t1;
	ac->call = &tc;
	t1 = (T21s6(ac));
	R = (((T29*)(t1))->a1);
	ac->call = tc.caller;
	return R;
}

/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].put */
void T29f2(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"CELL","put",ac->call};
	ac->call = &tc;
	((T29*)(C))->a1 = a1;
	ac->call = tc.caller;
}

/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].put */
T0* T29c2(TC* ac, T0* a1)
{
	GE_call tc = {"CELL","put",ac->call};
	T0* C;
	ac->call = &tc;
	C = GE_new29(ac, EIF_TRUE);
	((T29*)(C))->a1 = a1;
	ac->call = tc.caller;
	return C;
}

/* ISE_EXCEPTION_MANAGER.exception_data_cell */
T0* T21s6(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","exception_data_cell",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	if (GE_process_onces->reference_status[3]) {
		if (GE_process_onces->reference_exception[3]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[3]);
		}
		return GE_process_onces->reference_value[3];
	} else {
		GE_process_onces->reference_status[3] = '\1';
		GE_process_onces->reference_value[3] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[3] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	R = T29c2(ac, EIF_VOID);
	GE_process_onces->reference_value[3] = R;
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.once_raise */
void T21s15(TC* ac, T0* a1)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","once_raise",ac->call};
	T14 l1 = 0;
	T14 l2 = 0;
	T1 t1;
	T0* t2;
	T0* t3;
	T6 t4;
	T0* m1 = 0;
	ac->call = &tc;
	t1 = (T22x4669456(ac, a1));
	t1 = ((T1)(!(t1)));
	if (t1) {
		t1 = (T21s8(ac));
		if (t1) {
			t2 = (T22x4669448(ac, a1));
			t3 = (T21s1(ac));
			T22x4669468T0(ac, t2, t3);
		}
		T21s17(ac, a1);
		l1 = (T21s9(ac));
		t2 = (T22x4669460(ac, a1));
		t1 = (t2?((m1 = t2, EIF_TRUE)):EIF_FALSE);
		if (t1) {
			l2 = (T31f3(ac, m1));
		} else {
			l2 = (T21s9(ac));
		}
		t4 = (T22x4669447(ac, a1));
		GE_developer_raise((t4), (l1), (l2));
	}
	ac->call = tc.caller;
}

/* SERIALIZATION_FAILURE.code */
T6 T64f9(TC* ac, T0* C)
{
	GE_call tc = {"SERIALIZATION_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(31));
	ac->call = tc.caller;
	return R;
}

/* OLD_VIOLATION.code */
T6 T37f9(TC* ac, T0* C)
{
	GE_call tc = {"OLD_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(30));
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.code */
T6 T44f9(TC* ac, T0* C)
{
	GE_call tc = {"COM_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(28));
	ac->call = tc.caller;
	return R;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.code */
T6 T63f9(TC* ac, T0* C)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(26));
	ac->call = tc.caller;
	return R;
}

/* MISMATCH_FAILURE.code */
T6 T61f9(TC* ac, T0* C)
{
	GE_call tc = {"MISMATCH_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(23));
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_FAILURE.code */
T6 T43f9(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(22));
	ac->call = tc.caller;
	return R;
}

/* IO_FAILURE.code */
T6 T42f9(TC* ac, T0* C)
{
	GE_call tc = {"IO_FAILURE","code",ac->call};
	T6 R = 0;
	T1 t1;
	ac->call = &tc;
	t1 = (T1)((((T42*)(C))->a3) == ((T6)(GE_int32(21))));
	if (t1) {
		R = ((T42*)(C))->a3;
	} else {
		R = (T6)(GE_int32(27));
	}
	ac->call = tc.caller;
	return R;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.code */
T6 T60f9(TC* ac, T0* C)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(20));
	ac->call = tc.caller;
	return R;
}

/* VOID_ASSIGNED_TO_EXPANDED.code */
T6 T59f9(TC* ac, T0* C)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(19));
	ac->call = tc.caller;
	return R;
}

/* EXTERNAL_FAILURE.code */
T6 T58f9(TC* ac, T0* C)
{
	GE_call tc = {"EXTERNAL_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(18));
	ac->call = tc.caller;
	return R;
}

/* CREATE_ON_DEFERRED.code */
T6 T57f9(TC* ac, T0* C)
{
	GE_call tc = {"CREATE_ON_DEFERRED","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(17));
	ac->call = tc.caller;
	return R;
}

/* RESUMPTION_FAILURE.code */
T6 T56f9(TC* ac, T0* C)
{
	GE_call tc = {"RESUMPTION_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(16));
	ac->call = tc.caller;
	return R;
}

/* RESCUE_FAILURE.code */
T6 T55f9(TC* ac, T0* C)
{
	GE_call tc = {"RESCUE_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(14));
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.code */
T6 T41f9(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(12));
	ac->call = tc.caller;
	return R;
}

/* LOOP_INVARIANT_VIOLATION.code */
T6 T54f9(TC* ac, T0* C)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(11));
	ac->call = tc.caller;
	return R;
}

/* VARIANT_VIOLATION.code */
T6 T53f9(TC* ac, T0* C)
{
	GE_call tc = {"VARIANT_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(10));
	ac->call = tc.caller;
	return R;
}

/* BAD_INSPECT_VALUE.code */
T6 T52f9(TC* ac, T0* C)
{
	GE_call tc = {"BAD_INSPECT_VALUE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(9));
	ac->call = tc.caller;
	return R;
}

/* ROUTINE_FAILURE.code */
T6 T35f9(TC* ac, T0* C)
{
	GE_call tc = {"ROUTINE_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(8));
	ac->call = tc.caller;
	return R;
}

/* CHECK_VIOLATION.code */
T6 T51f9(TC* ac, T0* C)
{
	GE_call tc = {"CHECK_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(7));
	ac->call = tc.caller;
	return R;
}

/* INVARIANT_VIOLATION.code */
T6 T40f9(TC* ac, T0* C)
{
	GE_call tc = {"INVARIANT_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(6));
	ac->call = tc.caller;
	return R;
}

/* FLOATING_POINT_FAILURE.code */
T6 T50f9(TC* ac, T0* C)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(5));
	ac->call = tc.caller;
	return R;
}

/* POSTCONDITION_VIOLATION.code */
T6 T49f9(TC* ac, T0* C)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(4));
	ac->call = tc.caller;
	return R;
}

/* PRECONDITION_VIOLATION.code */
T6 T48f9(TC* ac, T0* C)
{
	GE_call tc = {"PRECONDITION_VIOLATION","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(3));
	ac->call = tc.caller;
	return R;
}

/* VOID_TARGET.code */
T6 T33f9(TC* ac, T0* C)
{
	GE_call tc = {"VOID_TARGET","code",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (T6)(GE_int32(1));
	ac->call = tc.caller;
	return R;
}

/* NO_MORE_MEMORY.c_description */
T0* T39f1(TC* ac, T0* C)
{
	GE_call tc = {"NO_MORE_MEMORY","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T39*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* SERIALIZATION_FAILURE.c_description */
T0* T64f1(TC* ac, T0* C)
{
	GE_call tc = {"SERIALIZATION_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T64*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* OLD_VIOLATION.c_description */
T0* T37f1(TC* ac, T0* C)
{
	GE_call tc = {"OLD_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T37*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.c_description */
T0* T44f1(TC* ac, T0* C)
{
	GE_call tc = {"COM_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T44*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.c_description */
T0* T63f1(TC* ac, T0* C)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T63*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* DEVELOPER_EXCEPTION.c_description */
T0* T62f1(TC* ac, T0* C)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T62*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* MISMATCH_FAILURE.c_description */
T0* T61f1(TC* ac, T0* C)
{
	GE_call tc = {"MISMATCH_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T61*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_FAILURE.c_description */
T0* T43f1(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T43*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* IO_FAILURE.c_description */
T0* T42f1(TC* ac, T0* C)
{
	GE_call tc = {"IO_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T42*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.c_description */
T0* T60f1(TC* ac, T0* C)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T60*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* VOID_ASSIGNED_TO_EXPANDED.c_description */
T0* T59f1(TC* ac, T0* C)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T59*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* EXTERNAL_FAILURE.c_description */
T0* T58f1(TC* ac, T0* C)
{
	GE_call tc = {"EXTERNAL_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T58*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* CREATE_ON_DEFERRED.c_description */
T0* T57f1(TC* ac, T0* C)
{
	GE_call tc = {"CREATE_ON_DEFERRED","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T57*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* RESUMPTION_FAILURE.c_description */
T0* T56f1(TC* ac, T0* C)
{
	GE_call tc = {"RESUMPTION_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T56*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* RESCUE_FAILURE.c_description */
T0* T55f1(TC* ac, T0* C)
{
	GE_call tc = {"RESCUE_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T55*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* EIFFEL_RUNTIME_PANIC.c_description */
T0* T45f1(TC* ac, T0* C)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T45*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.c_description */
T0* T41f1(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T41*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* LOOP_INVARIANT_VIOLATION.c_description */
T0* T54f1(TC* ac, T0* C)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T54*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* VARIANT_VIOLATION.c_description */
T0* T53f1(TC* ac, T0* C)
{
	GE_call tc = {"VARIANT_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T53*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* BAD_INSPECT_VALUE.c_description */
T0* T52f1(TC* ac, T0* C)
{
	GE_call tc = {"BAD_INSPECT_VALUE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T52*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* ROUTINE_FAILURE.c_description */
T0* T35f1(TC* ac, T0* C)
{
	GE_call tc = {"ROUTINE_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T35*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* CHECK_VIOLATION.c_description */
T0* T51f1(TC* ac, T0* C)
{
	GE_call tc = {"CHECK_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T51*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* INVARIANT_VIOLATION.c_description */
T0* T40f1(TC* ac, T0* C)
{
	GE_call tc = {"INVARIANT_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T40*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* FLOATING_POINT_FAILURE.c_description */
T0* T50f1(TC* ac, T0* C)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T50*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* POSTCONDITION_VIOLATION.c_description */
T0* T49f1(TC* ac, T0* C)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T49*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* PRECONDITION_VIOLATION.c_description */
T0* T48f1(TC* ac, T0* C)
{
	GE_call tc = {"PRECONDITION_VIOLATION","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T48*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* VOID_TARGET.c_description */
T0* T33f1(TC* ac, T0* C)
{
	GE_call tc = {"VOID_TARGET","c_description",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = ((T33*)(C))->a1;
	ac->call = tc.caller;
	return R;
}

/* NO_MORE_MEMORY.original */
T0* T39f10(TC* ac, T0* C)
{
	GE_call tc = {"NO_MORE_MEMORY","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T39*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* SERIALIZATION_FAILURE.original */
T0* T64f10(TC* ac, T0* C)
{
	GE_call tc = {"SERIALIZATION_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T64*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* OLD_VIOLATION.original */
T0* T37f10(TC* ac, T0* C)
{
	GE_call tc = {"OLD_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T37*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_TRUE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.original */
T0* T44f11(TC* ac, T0* C)
{
	GE_call tc = {"COM_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T44*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.original */
T0* T63f10(TC* ac, T0* C)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T63*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* DEVELOPER_EXCEPTION.original */
T0* T62f10(TC* ac, T0* C)
{
	GE_call tc = {"DEVELOPER_EXCEPTION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T62*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* MISMATCH_FAILURE.original */
T0* T61f10(TC* ac, T0* C)
{
	GE_call tc = {"MISMATCH_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T61*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_FAILURE.original */
T0* T43f10(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T43*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* IO_FAILURE.original */
T0* T42f10(TC* ac, T0* C)
{
	GE_call tc = {"IO_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T42*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.original */
T0* T60f10(TC* ac, T0* C)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T60*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* VOID_ASSIGNED_TO_EXPANDED.original */
T0* T59f10(TC* ac, T0* C)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T59*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* EXTERNAL_FAILURE.original */
T0* T58f10(TC* ac, T0* C)
{
	GE_call tc = {"EXTERNAL_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T58*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* CREATE_ON_DEFERRED.original */
T0* T57f10(TC* ac, T0* C)
{
	GE_call tc = {"CREATE_ON_DEFERRED","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T57*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* RESUMPTION_FAILURE.original */
T0* T56f10(TC* ac, T0* C)
{
	GE_call tc = {"RESUMPTION_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T56*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* RESCUE_FAILURE.original */
T0* T55f10(TC* ac, T0* C)
{
	GE_call tc = {"RESCUE_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T55*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* EIFFEL_RUNTIME_PANIC.original */
T0* T45f10(TC* ac, T0* C)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T45*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.original */
T0* T41f10(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T41*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* LOOP_INVARIANT_VIOLATION.original */
T0* T54f10(TC* ac, T0* C)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T54*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* VARIANT_VIOLATION.original */
T0* T53f10(TC* ac, T0* C)
{
	GE_call tc = {"VARIANT_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T53*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* BAD_INSPECT_VALUE.original */
T0* T52f10(TC* ac, T0* C)
{
	GE_call tc = {"BAD_INSPECT_VALUE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T52*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* ROUTINE_FAILURE.original */
T0* T35f10(TC* ac, T0* C)
{
	GE_call tc = {"ROUTINE_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T35*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_TRUE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* CHECK_VIOLATION.original */
T0* T51f10(TC* ac, T0* C)
{
	GE_call tc = {"CHECK_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T51*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* INVARIANT_VIOLATION.original */
T0* T40f10(TC* ac, T0* C)
{
	GE_call tc = {"INVARIANT_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T40*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* FLOATING_POINT_FAILURE.original */
T0* T50f10(TC* ac, T0* C)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T50*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* POSTCONDITION_VIOLATION.original */
T0* T49f10(TC* ac, T0* C)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T49*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* PRECONDITION_VIOLATION.original */
T0* T48f10(TC* ac, T0* C)
{
	GE_call tc = {"PRECONDITION_VIOLATION","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T48*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* VOID_TARGET.original */
T0* T33f10(TC* ac, T0* C)
{
	GE_call tc = {"VOID_TARGET","original",ac->call};
	T0* R = 0;
	T0* l1 = 0;
	T1 t1;
	ac->call = &tc;
	l1 = ((T33*)(C))->a2;
	t1 = (T1)(l1==C);
	if (!(t1)) {
		t1 = (T1)(l1==EIF_VOID);
	}
	if (t1) {
		R = C;
	} else {
		t1 = EIF_FALSE;
		if (!(t1)) {
			t1 = EIF_FALSE;
		}
		if (t1) {
			R = (T22x4669448(ac, l1));
		} else {
			R = C;
		}
	}
	ac->call = tc.caller;
	return R;
}

/* NO_MORE_MEMORY.is_ignored */
T1 T39f8(TC* ac, T0* C)
{
	GE_call tc = {"NO_MORE_MEMORY","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T39s11(ac));
	t2 = ((T0*)&(GE_types[39][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* NO_MORE_MEMORY.exception_manager */
T0* T39s11(TC* ac)
{
	GE_call tc = {"NO_MORE_MEMORY","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* SERIALIZATION_FAILURE.is_ignored */
T1 T64f8(TC* ac, T0* C)
{
	GE_call tc = {"SERIALIZATION_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T64s6(ac));
	t2 = ((T0*)&(GE_types[64][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* SERIALIZATION_FAILURE.exception_manager */
T0* T64s6(TC* ac)
{
	GE_call tc = {"SERIALIZATION_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* OLD_VIOLATION.is_ignored */
T1 T37f8(TC* ac, T0* C)
{
	GE_call tc = {"OLD_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T37s6(ac));
	t2 = ((T0*)&(GE_types[37][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* OLD_VIOLATION.exception_manager */
T0* T37s6(TC* ac)
{
	GE_call tc = {"OLD_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.is_ignored */
T1 T44f16(TC* ac, T0* C)
{
	GE_call tc = {"COM_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T44s14(ac));
	t2 = ((T0*)&(GE_types[44][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* COM_FAILURE.exception_manager */
T0* T44s14(TC* ac)
{
	GE_call tc = {"COM_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.is_ignored */
T1 T63f8(TC* ac, T0* C)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T63s6(ac));
	t2 = ((T0*)&(GE_types[63][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* ADDRESS_APPLIED_TO_MELTED_FEATURE.exception_manager */
T0* T63s6(TC* ac)
{
	GE_call tc = {"ADDRESS_APPLIED_TO_MELTED_FEATURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* MISMATCH_FAILURE.is_ignored */
T1 T61f8(TC* ac, T0* C)
{
	GE_call tc = {"MISMATCH_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T61s6(ac));
	t2 = ((T0*)&(GE_types[61][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* MISMATCH_FAILURE.exception_manager */
T0* T61s6(TC* ac)
{
	GE_call tc = {"MISMATCH_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_FAILURE.is_ignored */
T1 T43f8(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T43s11(ac));
	t2 = ((T0*)&(GE_types[43][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_FAILURE.exception_manager */
T0* T43s11(TC* ac)
{
	GE_call tc = {"OPERATING_SYSTEM_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* IO_FAILURE.is_ignored */
T1 T42f8(TC* ac, T0* C)
{
	GE_call tc = {"IO_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T42s11(ac));
	t2 = ((T0*)&(GE_types[42][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* IO_FAILURE.exception_manager */
T0* T42s11(TC* ac)
{
	GE_call tc = {"IO_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.is_ignored */
T1 T60f8(TC* ac, T0* C)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T60s6(ac));
	t2 = ((T0*)&(GE_types[60][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.exception_manager */
T0* T60s6(TC* ac)
{
	GE_call tc = {"EXCEPTION_IN_SIGNAL_HANDLER_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* VOID_ASSIGNED_TO_EXPANDED.is_ignored */
T1 T59f8(TC* ac, T0* C)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T59s6(ac));
	t2 = ((T0*)&(GE_types[59][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* VOID_ASSIGNED_TO_EXPANDED.exception_manager */
T0* T59s6(TC* ac)
{
	GE_call tc = {"VOID_ASSIGNED_TO_EXPANDED","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* EXTERNAL_FAILURE.is_ignored */
T1 T58f8(TC* ac, T0* C)
{
	GE_call tc = {"EXTERNAL_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T58s6(ac));
	t2 = ((T0*)&(GE_types[58][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* EXTERNAL_FAILURE.exception_manager */
T0* T58s6(TC* ac)
{
	GE_call tc = {"EXTERNAL_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* CREATE_ON_DEFERRED.is_ignored */
T1 T57f8(TC* ac, T0* C)
{
	GE_call tc = {"CREATE_ON_DEFERRED","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T57s6(ac));
	t2 = ((T0*)&(GE_types[57][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* CREATE_ON_DEFERRED.exception_manager */
T0* T57s6(TC* ac)
{
	GE_call tc = {"CREATE_ON_DEFERRED","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* RESUMPTION_FAILURE.is_ignored */
T1 T56f8(TC* ac, T0* C)
{
	GE_call tc = {"RESUMPTION_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T56s6(ac));
	t2 = ((T0*)&(GE_types[56][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* RESUMPTION_FAILURE.exception_manager */
T0* T56s6(TC* ac)
{
	GE_call tc = {"RESUMPTION_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* RESCUE_FAILURE.is_ignored */
T1 T55f8(TC* ac, T0* C)
{
	GE_call tc = {"RESCUE_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T55s6(ac));
	t2 = ((T0*)&(GE_types[55][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* RESCUE_FAILURE.exception_manager */
T0* T55s6(TC* ac)
{
	GE_call tc = {"RESCUE_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* EIFFEL_RUNTIME_PANIC.is_ignored */
T1 T45f8(TC* ac, T0* C)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T45s11(ac));
	t2 = ((T0*)&(GE_types[45][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* EIFFEL_RUNTIME_PANIC.exception_manager */
T0* T45s11(TC* ac)
{
	GE_call tc = {"EIFFEL_RUNTIME_PANIC","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.is_ignored */
T1 T41f8(TC* ac, T0* C)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T41s11(ac));
	t2 = ((T0*)&(GE_types[41][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* OPERATING_SYSTEM_SIGNAL_FAILURE.exception_manager */
T0* T41s11(TC* ac)
{
	GE_call tc = {"OPERATING_SYSTEM_SIGNAL_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* LOOP_INVARIANT_VIOLATION.is_ignored */
T1 T54f8(TC* ac, T0* C)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T54s6(ac));
	t2 = ((T0*)&(GE_types[54][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* LOOP_INVARIANT_VIOLATION.exception_manager */
T0* T54s6(TC* ac)
{
	GE_call tc = {"LOOP_INVARIANT_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* VARIANT_VIOLATION.is_ignored */
T1 T53f8(TC* ac, T0* C)
{
	GE_call tc = {"VARIANT_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T53s6(ac));
	t2 = ((T0*)&(GE_types[53][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* VARIANT_VIOLATION.exception_manager */
T0* T53s6(TC* ac)
{
	GE_call tc = {"VARIANT_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* BAD_INSPECT_VALUE.is_ignored */
T1 T52f8(TC* ac, T0* C)
{
	GE_call tc = {"BAD_INSPECT_VALUE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T52s6(ac));
	t2 = ((T0*)&(GE_types[52][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* BAD_INSPECT_VALUE.exception_manager */
T0* T52s6(TC* ac)
{
	GE_call tc = {"BAD_INSPECT_VALUE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* ROUTINE_FAILURE.is_ignored */
T1 T35f8(TC* ac, T0* C)
{
	GE_call tc = {"ROUTINE_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T35s11(ac));
	t2 = ((T0*)&(GE_types[35][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* ROUTINE_FAILURE.exception_manager */
T0* T35s11(TC* ac)
{
	GE_call tc = {"ROUTINE_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* CHECK_VIOLATION.is_ignored */
T1 T51f8(TC* ac, T0* C)
{
	GE_call tc = {"CHECK_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T51s6(ac));
	t2 = ((T0*)&(GE_types[51][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* CHECK_VIOLATION.exception_manager */
T0* T51s6(TC* ac)
{
	GE_call tc = {"CHECK_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* INVARIANT_VIOLATION.is_ignored */
T1 T40f8(TC* ac, T0* C)
{
	GE_call tc = {"INVARIANT_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T40s11(ac));
	t2 = ((T0*)&(GE_types[40][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* INVARIANT_VIOLATION.exception_manager */
T0* T40s11(TC* ac)
{
	GE_call tc = {"INVARIANT_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* FLOATING_POINT_FAILURE.is_ignored */
T1 T50f8(TC* ac, T0* C)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T50s6(ac));
	t2 = ((T0*)&(GE_types[50][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* FLOATING_POINT_FAILURE.exception_manager */
T0* T50s6(TC* ac)
{
	GE_call tc = {"FLOATING_POINT_FAILURE","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* POSTCONDITION_VIOLATION.is_ignored */
T1 T49f8(TC* ac, T0* C)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T49s6(ac));
	t2 = ((T0*)&(GE_types[49][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* POSTCONDITION_VIOLATION.exception_manager */
T0* T49s6(TC* ac)
{
	GE_call tc = {"POSTCONDITION_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* PRECONDITION_VIOLATION.is_ignored */
T1 T48f8(TC* ac, T0* C)
{
	GE_call tc = {"PRECONDITION_VIOLATION","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T48s6(ac));
	t2 = ((T0*)&(GE_types[48][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* PRECONDITION_VIOLATION.exception_manager */
T0* T48s6(TC* ac)
{
	GE_call tc = {"PRECONDITION_VIOLATION","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* VOID_TARGET.is_ignored */
T1 T33f8(TC* ac, T0* C)
{
	GE_call tc = {"VOID_TARGET","is_ignored",ac->call};
	T1 R = 0;
	T0* t1;
	T0* t2;
	ac->call = &tc;
	t1 = (T33s6(ac));
	t2 = ((T0*)&(GE_types[33][0]));
	R = (T21s13(ac, t2));
	ac->call = tc.caller;
	return R;
}

/* VOID_TARGET.exception_manager */
T0* T33s6(TC* ac)
{
	GE_call tc = {"VOID_TARGET","exception_manager",ac->call};
	T0* R = 0;
	ac->call = &tc;
	{
	R = ac->exception_manager;
	}
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.last_exception */
T0* T21s1(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","last_exception",ac->call};
	T0* R = 0;
	T0* t1;
	ac->call = &tc;
	t1 = (T21s2(ac));
	R = (((T27*)(t1))->a1);
	ac->call = tc.caller;
	return R;
}

/* ISE_EXCEPTION_MANAGER.init_exception_manager */
void T21s14(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","init_exception_manager",ac->call};
	T0* t1;
	ac->call = &tc;
	t1 = (T21s3(ac));
	T28s36(ac);
	t1 = (T21s4(ac));
	T28s36(ac);
	t1 = (T21s5(ac));
	T28s36(ac);
	t1 = (T21s6(ac));
	T29s3(ac);
	t1 = (T21s2(ac));
	T27s3(ac);
	t1 = (T21s7(ac));
	T30s3(ac);
	ac->call = tc.caller;
}

/* CELL [NO_MORE_MEMORY].do_nothing */
void T30s3(TC* ac)
{
}

/* CELL [detachable EXCEPTION].do_nothing */
void T27s3(TC* ac)
{
}

/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].do_nothing */
void T29s3(TC* ac)
{
}

/* ISE_EXCEPTION_MANAGER.unraisable_exceptions */
T0* T21s5(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","unraisable_exceptions",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	T6 l1 = 0;
	if (GE_process_onces->reference_status[4]) {
		if (GE_process_onces->reference_exception[4]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[4]);
		}
		return GE_process_onces->reference_value[4];
	} else {
		GE_process_onces->reference_status[4] = '\1';
		GE_process_onces->reference_value[4] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[4] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	R = T28c35(ac, (T6)(GE_int32(2)));
	GE_process_onces->reference_value[4] = R;
	l1 = (((EIF_TYPE_OBJ*)(((T0*)&(GE_types[35][1]))))->type_id);
	T28f37(ac, R, l1, l1);
	l1 = (((EIF_TYPE_OBJ*)(((T0*)&(GE_types[37][1]))))->type_id);
	T28f37(ac, R, l1, l1);
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].force */
void T28f37(TC* ac, T0* C, T6 a1, T6 a2)
{
	GE_call tc = {"HASH_TABLE","force",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 l4 = 0;
	T1 t1;
	ac->call = &tc;
	T28f38(ac, C, a2);
	t1 = (T28f19(ac, C));
	if (t1) {
		t1 = (T28f20(ac, C));
		if (t1) {
			T28f39(ac, C);
			T28f38(ac, C, a2);
		}
		t1 = (T1)((((T28*)(C))->a8) == ((T6)(GE_int32(-1))));
		if (t1) {
			l3 = (((T66*)(((T28*)(C))->a3))->a2);
			l4 = ((T28*)(C))->a12;
		} else {
			l3 = (T28f21(ac, C, ((T28*)(C))->a8));
			l4 = ((T28*)(C))->a8;
			T67f5(ac, ((T28*)(C))->a4, EIF_FALSE, l3);
		}
		((T66*)(((T28*)(C))->a5))->z2[l4] = (l3);
		T66f7(ac, ((T28*)(C))->a3, a2, l3);
		t1 = (T1)((a2) == (l1));
		if (t1) {
			((T28*)(C))->a11 = EIF_TRUE;
		}
		((T28*)(C))->a7 = ((T6)((((T28*)(C))->a7)+((T6)(GE_int32(1)))));
		((T28*)(C))->a10 = l2;
	} else {
		l3 = (T28f22(ac, C));
		((T28*)(C))->a10 = (((T66*)(((T28*)(C))->a2))->z2[l3]);
	}
	T66f7(ac, ((T28*)(C))->a2, a1, l3);
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].position */
T6 T28f22(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","position",ac->call};
	T6 R = 0;
	ac->call = &tc;
	R = (((T66*)(((T28*)(C))->a5))->z2[((T28*)(C))->a12]);
	ac->call = tc.caller;
	return R;
}

/* SPECIAL [INTEGER_32].force */
void T66f7(TC* ac, T0* C, T6 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","force",ac->call};
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((a2)<(((T66*)(C))->a2)));
	if (t1) {
		((T66*)(C))->z2[a2] = (a1);
	} else {
		T66f9(ac, C, a1);
	}
	ac->call = tc.caller;
}

/* SPECIAL [BOOLEAN].force */
void T67f5(TC* ac, T0* C, T1 a1, T6 a2)
{
	GE_call tc = {"SPECIAL","force",ac->call};
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)((a2)<(((T67*)(C))->a2)));
	if (t1) {
		((T67*)(C))->z2[a2] = (a1);
	} else {
		T67f9(ac, C, a1);
	}
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].deleted_position */
T6 T28f21(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","deleted_position",ac->call};
	T6 volatile R = 0;
	T6 t1;
	ac->call = &tc;
	t1 = (((T66*)(((T28*)(C))->a5))->z2[a1]);
	t1 = ((T6)(-(t1)));
	R = ((T6)((t1)+((T6)(GE_int32(-2)))));
	t1 = (((T66*)(((T28*)(C))->a3))->a2);
	R = (T6f12(ac, (&R), t1));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].add_space */
void T28f39(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","add_space",ac->call};
	T6 t1;
	ac->call = &tc;
	t1 = ((T6)((((T28*)(C))->a7)/((T6)(GE_int32(2)))));
	t1 = ((T6)((((T28*)(C))->a7)+(t1)));
	T28f40(ac, C, t1);
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].accommodate */
void T28f40(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","accommodate",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T0* l3 = 0;
	T0* l4 = 0;
	T0* l5 = 0;
	T6 volatile t1;
	T1 t2;
	T6 t3;
	T6 t4;
	T0* t5;
	ac->call = &tc;
	t1 = (((T66*)(((T28*)(C))->a3))->a2);
	t1 = (T6f4(ac, &t1, a1));
	l3 = (T28f28(ac, C, t1));
	l4 = ((T28*)(C))->a2;
	l5 = ((T28*)(C))->a3;
	l2 = (((T66*)(l5))->a2);
	while (1) {
		t2 = (T1)((l1) == (l2));
		if (t2) {
			break;
		}
		t2 = (T28f29(ac, C, l1));
		if (t2) {
			t3 = (((T66*)(l4))->z2[l1]);
			t4 = (((T66*)(l5))->z2[l1]);
			T28f45(ac, l3, t3, t4);
		}
		l1 = ((T6)((l1)+((T6)(GE_int32(1)))));
	}
	if (((T28*)(C))->a11) {
		l1 = (((T66*)(((T28*)(C))->a5))->z2[((T28*)(C))->a1]);
		t3 = (((T66*)(l4))->z2[l1]);
		t4 = (((T66*)(((T28*)(C))->a3))->z2[l1]);
		T28f45(ac, l3, t3, t4);
	}
	t5 = (((T28*)(l3))->a2);
	T28f41(ac, C, t5);
	t5 = (((T28*)(l3))->a3);
	T28f42(ac, C, t5);
	t5 = (((T28*)(l3))->a4);
	T28f43(ac, C, t5);
	t5 = (((T28*)(l3))->a5);
	T28f44(ac, C, t5);
	((T28*)(C))->a1 = (((T28*)(l3))->a1);
	((T28*)(C))->a6 = (((T28*)(l3))->a6);
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].set_indexes_map */
void T28f44(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"HASH_TABLE","set_indexes_map",ac->call};
	ac->call = &tc;
	((T28*)(C))->a5 = a1;
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].set_deleted_marks */
void T28f43(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"HASH_TABLE","set_deleted_marks",ac->call};
	ac->call = &tc;
	((T28*)(C))->a4 = a1;
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].set_keys */
void T28f42(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"HASH_TABLE","set_keys",ac->call};
	ac->call = &tc;
	((T28*)(C))->a3 = a1;
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].set_content */
void T28f41(TC* ac, T0* C, T0* a1)
{
	GE_call tc = {"HASH_TABLE","set_content",ac->call};
	ac->call = &tc;
	((T28*)(C))->a2 = a1;
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].put */
void T28f45(TC* ac, T0* C, T6 a1, T6 a2)
{
	GE_call tc = {"HASH_TABLE","put",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T1 t1;
	T6 t2;
	ac->call = &tc;
	T28f38(ac, C, a2);
	t1 = (T28f31(ac, C));
	if (t1) {
		T28f47(ac, C);
		t2 = (T28f22(ac, C));
		((T28*)(C))->a10 = (((T66*)(((T28*)(C))->a2))->z2[t2]);
	} else {
		t1 = (T28f20(ac, C));
		if (t1) {
			T28f39(ac, C);
			T28f38(ac, C, a2);
		}
		t1 = (T1)((((T28*)(C))->a8) == ((T6)(GE_int32(-1))));
		if (t1) {
			l2 = (((T66*)(((T28*)(C))->a3))->a2);
			l3 = ((T28*)(C))->a12;
		} else {
			l2 = (T28f21(ac, C, ((T28*)(C))->a8));
			l3 = ((T28*)(C))->a8;
			T67f5(ac, ((T28*)(C))->a4, EIF_FALSE, l2);
		}
		((T66*)(((T28*)(C))->a5))->z2[l3] = (l2);
		T66f7(ac, ((T28*)(C))->a2, a1, l2);
		T66f7(ac, ((T28*)(C))->a3, a2, l2);
		t1 = (T1)((a2) == (l1));
		if (t1) {
			((T28*)(C))->a11 = EIF_TRUE;
		}
		((T28*)(C))->a7 = ((T6)((((T28*)(C))->a7)+((T6)(GE_int32(1)))));
		((T28*)(C))->a10 = a1;
		((T28*)(C))->a9 = (T6)(GE_int32(4));
	}
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].set_conflict */
void T28f47(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","set_conflict",ac->call};
	ac->call = &tc;
	((T28*)(C))->a9 = (T6)(GE_int32(1));
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].found */
T1 T28f31(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","found",ac->call};
	T1 R = 0;
	ac->call = &tc;
	R = (T1)((((T28*)(C))->a9) == ((T6)(GE_int32(2))));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].occupied */
T1 T28f29(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","occupied",ac->call};
	T1 R = 0;
	T6 t1;
	T1 t2;
	ac->call = &tc;
	if (((T28*)(C))->a11) {
		t1 = (((T66*)(((T28*)(C))->a5))->z2[((T28*)(C))->a1]);
		t2 = (T1)(!(T1)((a1) == (t1)));
		if (t2) {
			t2 = (((T67*)(((T28*)(C))->a4))->z2[a1]);
			R = ((T1)(!(t2)));
		} else {
			R = EIF_FALSE;
		}
	} else {
		t2 = (((T67*)(((T28*)(C))->a4))->z2[a1]);
		R = ((T1)(!(t2)));
	}
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].empty_duplicate */
T0* T28f28(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","empty_duplicate",ac->call};
	T0* R = 0;
	ac->call = &tc;
	R = T28c35(ac, a1);
	if (((T28*)(C))->a16) {
		T28f46(ac, R);
	}
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].compare_objects */
void T28f46(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","compare_objects",ac->call};
	ac->call = &tc;
	((T28*)(C))->a16 = EIF_TRUE;
	ac->call = tc.caller;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].soon_full */
T1 T28f20(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","soon_full",ac->call};
	T1 R = 0;
	T6 t1;
	T6 t2;
	ac->call = &tc;
	t1 = (((T66*)(((T28*)(C))->a3))->a2);
	t2 = (((T66*)(((T28*)(C))->a3))->a1);
	R = (T1)((t1) == (t2));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].not_found */
T1 T28f19(TC* ac, T0* C)
{
	GE_call tc = {"HASH_TABLE","not_found",ac->call};
	T1 R = 0;
	ac->call = &tc;
	R = (T1)((((T28*)(C))->a9) == ((T6)(GE_int32(8))));
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].internal_search */
void T28f38(TC* ac, T0* C, T6 a1)
{
	GE_call tc = {"HASH_TABLE","internal_search",ac->call};
	T6 l1 = 0;
	T6 l2 = 0;
	T6 l3 = 0;
	T6 volatile l4 = 0;
	T6 l5 = 0;
	T6 l6 = 0;
	T6 l7 = 0;
	T6 l8 = 0;
	T0* l9 = 0;
	T0* l10 = 0;
	T0* l11 = 0;
	T6 l12 = 0;
	T1 t1;
	T6 t2;
	T6 t3;
	ac->call = &tc;
	l7 = (T6)(GE_int32(-1));
	t1 = (T1)((a1) == (l1));
	if (!(t1)) {
		t1 = EIF_FALSE;
	}
	if (t1) {
		((T28*)(C))->a12 = ((T28*)(C))->a1;
		if (((T28*)(C))->a11) {
			((T28*)(C))->a9 = (T6)(GE_int32(2));
		} else {
			((T28*)(C))->a9 = (T6)(GE_int32(8));
		}
	} else {
		l9 = ((T28*)(C))->a3;
		l10 = ((T28*)(C))->a5;
		l11 = ((T28*)(C))->a4;
		l6 = ((T28*)(C))->a1;
		l8 = l6;
		l2 = (T28f25(ac, C, a1));
		t2 = (T6)(GE_int32(1));
		t3 = ((T6)((l6)-((T6)(GE_int32(1)))));
		t3 = ((T6)((l2)%(t3)));
		l3 = ((T6)((t2)+(t3)));
		t2 = ((T6)((l2)%(l6)));
		l5 = ((T6)((t2)-(l3)));
		((T28*)(C))->a9 = (T6)(GE_int32(8));
		while (1) {
			t1 = (T1)((l8) == ((T6)(GE_int32(0))));
			if (t1) {
				break;
			}
			t2 = ((T6)((l5)+(l3)));
			l5 = ((T6)((t2)%(l6)));
			l4 = (((T66*)(l10))->z2[l5]);
			t1 = (T6f9(ac, (&l4), (T6)(GE_int32(0))));
			if (t1) {
				l12 = (((T66*)(l9))->z2[l4]);
				t1 = (T28f26(ac, C, l12, a1));
				if (t1) {
					l8 = (T6)(GE_int32(1));
					((T28*)(C))->a9 = (T6)(GE_int32(2));
				}
			} else {
				t1 = (T1)((l4) == ((T6)(GE_int32(-1))));
				if (t1) {
					l8 = (T6)(GE_int32(1));
				} else {
					t1 = (T1)((l7) == ((T6)(GE_int32(-1))));
					if (t1) {
						t2 = ((T6)(-(l4)));
						l4 = ((T6)((t2)+((T6)(GE_int32(-2)))));
						t1 = (((T67*)(l11))->z2[l4]);
						t1 = ((T1)(!(t1)));
						if (t1) {
							l8 = (T6)(GE_int32(1));
						} else {
							l7 = l5;
						}
					}
				}
			}
			l8 = ((T6)((l8)-((T6)(GE_int32(1)))));
		}
		((T28*)(C))->a12 = l5;
	}
	((T28*)(C))->a8 = l7;
	ac->call = tc.caller;
}

/* ISE_EXCEPTION_MANAGER.unignorable_exceptions */
T0* T21s4(TC* ac)
{
	GE_call tc = {"ISE_EXCEPTION_MANAGER","unignorable_exceptions",ac->call};
	GE_rescue r;
	volatile uint32_t tr = ac->in_rescue;
	T0* R = 0;
	T6 l1 = 0;
	if (GE_process_onces->reference_status[5]) {
		if (GE_process_onces->reference_exception[5]) {
			GE_raise_once_exception(ac, GE_process_onces->reference_exception[5]);
		}
		return GE_process_onces->reference_value[5];
	} else {
		GE_process_onces->reference_status[5] = '\1';
		GE_process_onces->reference_value[5] = R;
	}
	ac->call = &tc;
	r.previous = ac->last_rescue;
	ac->last_rescue = &r;
	if (GE_setjmp(r.jb) != 0) {
		ac->last_rescue = &r;
		ac->in_rescue = tr + 1;
		GE_process_onces->reference_exception[5] = GE_last_exception_raised(ac);
		ac->last_rescue = r.previous;
		GE_jump_to_last_rescue(ac);
	}
	R = T28c35(ac, (T6)(GE_int32(1)));
	GE_process_onces->reference_value[5] = R;
	l1 = (((EIF_TYPE_OBJ*)(((T0*)&(GE_types[33][1]))))->type_id);
	T28f37(ac, R, l1, l1);
	ac->last_rescue = r.previous;
	ac->call = tc.caller;
	return R;
}

/* HASH_TABLE [INTEGER_32, INTEGER_32].do_nothing */
void T28s36(TC* ac)
{
}

/* MANAGED_POINTER.dispose */
void T73f6(TC* ac, T0* C)
{
	GE_call tc = {"MANAGED_POINTER","dispose",ac->call};
	T14 l1 = 0;
	T1 t1;
	ac->call = &tc;
	t1 = ((T1)(!(((T73*)(C))->a3)));
	if (t1) {
		T14f11(ac, &(((T73*)(C))->a1));
	}
	((T73*)(C))->a1 = l1;
	((T73*)(C))->a3 = EIF_FALSE;
	ac->call = tc.caller;
}

/* POINTER.memory_free */
void T14f11(TC* ac, T14 volatile* C)
{
	GE_call tc = {"POINTER","memory_free",ac->call};
	T14 t1;
	ac->call = &tc;
	T14s14(ac, *C);
	t1 = (T14s9(ac));
	*C = (t1);
	ac->call = tc.caller;
}

/* POINTER.default_pointer */
T14 T14s9(TC* ac)
{
	T14 R = 0;
	return R;
}

/* POINTER.c_free */
void T14s14(TC* ac, T14 a1)
{
	GE_call tc = {"POINTER","c_free",ac->call};
	ac->call = &tc;
	{
	free((void *)(void*)a1);
	}
	ac->call = tc.caller;
}

/* Call to EXCEPTION.original */
T0* T22x4669448(TC* ac, T0* C)
{
	switch (((T0*)(C))->id) {
	case 33:
		return (T33f10(ac, C));
	case 35:
		return (T35f10(ac, C));
	case 37:
		return (T37f10(ac, C));
	case 39:
		return (T39f10(ac, C));
	case 40:
		return (T40f10(ac, C));
	case 41:
		return (T41f10(ac, C));
	case 42:
		return (T42f10(ac, C));
	case 43:
		return (T43f10(ac, C));
	case 44:
		return (T44f11(ac, C));
	case 45:
		return (T45f10(ac, C));
	case 48:
		return (T48f10(ac, C));
	case 49:
		return (T49f10(ac, C));
	case 50:
		return (T50f10(ac, C));
	case 51:
		return (T51f10(ac, C));
	case 52:
		return (T52f10(ac, C));
	case 53:
		return (T53f10(ac, C));
	case 54:
		return (T54f10(ac, C));
	case 55:
		return (T55f10(ac, C));
	case 56:
		return (T56f10(ac, C));
	case 57:
		return (T57f10(ac, C));
	case 58:
		return (T58f10(ac, C));
	case 59:
		return (T59f10(ac, C));
	case 60:
		return (T60f10(ac, C));
	case 61:
		return (T61f10(ac, C));
	case 62:
		return (T62f10(ac, C));
	case 63:
		return (T63f10(ac, C));
	case 64:
		return (T64f10(ac, C));
	default:
		return 0;
	}
}

/* Call to EXCEPTION.code */
T6 T22x4669447(TC* ac, T0* C)
{
	switch (((T0*)(C))->id) {
	case 33:
		return (T33f9(ac, C));
	case 35:
		return (T35f9(ac, C));
	case 37:
		return (T37f9(ac, C));
	case 39:
		return (T39f9(ac, C));
	case 40:
		return (T40f9(ac, C));
	case 41:
		return (T41f9(ac, C));
	case 42:
		return (T42f9(ac, C));
	case 43:
		return (T43f9(ac, C));
	case 44:
		return (T44f9(ac, C));
	case 45:
		return (T45f9(ac, C));
	case 48:
		return (T48f9(ac, C));
	case 49:
		return (T49f9(ac, C));
	case 50:
		return (T50f9(ac, C));
	case 51:
		return (T51f9(ac, C));
	case 52:
		return (T52f9(ac, C));
	case 53:
		return (T53f9(ac, C));
	case 54:
		return (T54f9(ac, C));
	case 55:
		return (T55f9(ac, C));
	case 56:
		return (T56f9(ac, C));
	case 57:
		return (T57f9(ac, C));
	case 58:
		return (T58f9(ac, C));
	case 59:
		return (T59f9(ac, C));
	case 60:
		return (T60f9(ac, C));
	case 61:
		return (T61f9(ac, C));
	case 62:
		return (T62f9(ac, C));
	case 63:
		return (T63f9(ac, C));
	case 64:
		return (T64f9(ac, C));
	default:
		return 0;
	}
}

/* Call to EXCEPTION.c_description */
T0* T22x4669460(TC* ac, T0* C)
{
	switch (((T0*)(C))->id) {
	case 33:
		return (((T33*)(C))->a1);
	case 35:
		return (((T35*)(C))->a1);
	case 37:
		return (((T37*)(C))->a1);
	case 39:
		return (((T39*)(C))->a1);
	case 40:
		return (((T40*)(C))->a1);
	case 41:
		return (((T41*)(C))->a1);
	case 42:
		return (((T42*)(C))->a1);
	case 43:
		return (((T43*)(C))->a1);
	case 44:
		return (((T44*)(C))->a1);
	case 45:
		return (((T45*)(C))->a1);
	case 48:
		return (((T48*)(C))->a1);
	case 49:
		return (((T49*)(C))->a1);
	case 50:
		return (((T50*)(C))->a1);
	case 51:
		return (((T51*)(C))->a1);
	case 52:
		return (((T52*)(C))->a1);
	case 53:
		return (((T53*)(C))->a1);
	case 54:
		return (((T54*)(C))->a1);
	case 55:
		return (((T55*)(C))->a1);
	case 56:
		return (((T56*)(C))->a1);
	case 57:
		return (((T57*)(C))->a1);
	case 58:
		return (((T58*)(C))->a1);
	case 59:
		return (((T59*)(C))->a1);
	case 60:
		return (((T60*)(C))->a1);
	case 61:
		return (((T61*)(C))->a1);
	case 62:
		return (((T62*)(C))->a1);
	case 63:
		return (((T63*)(C))->a1);
	case 64:
		return (((T64*)(C))->a1);
	default:
		return 0;
	}
}

/* Call to EXCEPTION.is_ignored */
T1 T22x4669456(TC* ac, T0* C)
{
	switch (((T0*)(C))->id) {
	case 33:
		return (T33f8(ac, C));
	case 35:
		return (T35f8(ac, C));
	case 37:
		return (T37f8(ac, C));
	case 39:
		return (T39f8(ac, C));
	case 40:
		return (T40f8(ac, C));
	case 41:
		return (T41f8(ac, C));
	case 42:
		return (T42f8(ac, C));
	case 43:
		return (T43f8(ac, C));
	case 44:
		return (T44f16(ac, C));
	case 45:
		return (T45f8(ac, C));
	case 48:
		return (T48f8(ac, C));
	case 49:
		return (T49f8(ac, C));
	case 50:
		return (T50f8(ac, C));
	case 51:
		return (T51f8(ac, C));
	case 52:
		return (T52f8(ac, C));
	case 53:
		return (T53f8(ac, C));
	case 54:
		return (T54f8(ac, C));
	case 55:
		return (T55f8(ac, C));
	case 56:
		return (T56f8(ac, C));
	case 57:
		return (T57f8(ac, C));
	case 58:
		return (T58f8(ac, C));
	case 59:
		return (T59f8(ac, C));
	case 60:
		return (T60f8(ac, C));
	case 61:
		return (T61f8(ac, C));
	case 62:
		return (T62f8(ac, C));
	case 63:
		return (T63f8(ac, C));
	case 64:
		return (T64f8(ac, C));
	default:
		return 0;
	}
}

/* Call to TYPE [detachable EXCEPTION].type_id */
T6 T70x3883012(TC* ac, T0* C)
{
	switch (((T0*)(C))->id) {
	case 69:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 74:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 75:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 76:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 77:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 78:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 79:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 80:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 81:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 82:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 83:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 84:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 85:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 86:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 87:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 88:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 89:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 90:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 91:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 92:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 93:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 94:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 95:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 96:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 97:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 98:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	case 99:
		return (((EIF_TYPE_OBJ*)(C))->type_id);
	default:
		return 0;
	}
}

/* Call to EXCEPTION.set_type_name */
void T22x4669464T0(TC* ac, T0* C, T0* a1)
{
	switch (((T0*)(C))->id) {
	case 33:
		T33f16(ac, C, a1);
		break;
	case 35:
		T35f20(ac, C, a1);
		break;
	case 37:
		T37f16(ac, C, a1);
		break;
	case 39:
		T39f18(ac, C, a1);
		break;
	case 40:
		T40f18(ac, C, a1);
		break;
	case 41:
		T41f18(ac, C, a1);
		break;
	case 42:
		T42f20(ac, C, a1);
		break;
	case 43:
		T43f18(ac, C, a1);
		break;
	case 44:
		T44f24(ac, C, a1);
		break;
	case 45:
		T45f18(ac, C, a1);
		break;
	case 48:
		T48f16(ac, C, a1);
		break;
	case 49:
		T49f16(ac, C, a1);
		break;
	case 50:
		T50f16(ac, C, a1);
		break;
	case 51:
		T51f16(ac, C, a1);
		break;
	case 52:
		T52f16(ac, C, a1);
		break;
	case 53:
		T53f16(ac, C, a1);
		break;
	case 54:
		T54f16(ac, C, a1);
		break;
	case 55:
		T55f16(ac, C, a1);
		break;
	case 56:
		T56f16(ac, C, a1);
		break;
	case 57:
		T57f16(ac, C, a1);
		break;
	case 58:
		T58f16(ac, C, a1);
		break;
	case 59:
		T59f16(ac, C, a1);
		break;
	case 60:
		T60f16(ac, C, a1);
		break;
	case 61:
		T61f16(ac, C, a1);
		break;
	case 62:
		T62f16(ac, C, a1);
		break;
	case 63:
		T63f16(ac, C, a1);
		break;
	case 64:
		T64f16(ac, C, a1);
		break;
	}
}

/* Call to EXCEPTION.set_recipient_name */
void T22x4669467T0(TC* ac, T0* C, T0* a1)
{
	switch (((T0*)(C))->id) {
	case 33:
		T33f15(ac, C, a1);
		break;
	case 35:
		T35f19(ac, C, a1);
		break;
	case 37:
		T37f15(ac, C, a1);
		break;
	case 39:
		T39f17(ac, C, a1);
		break;
	case 40:
		T40f17(ac, C, a1);
		break;
	case 41:
		T41f17(ac, C, a1);
		break;
	case 42:
		T42f19(ac, C, a1);
		break;
	case 43:
		T43f17(ac, C, a1);
		break;
	case 44:
		T44f23(ac, C, a1);
		break;
	case 45:
		T45f17(ac, C, a1);
		break;
	case 48:
		T48f15(ac, C, a1);
		break;
	case 49:
		T49f15(ac, C, a1);
		break;
	case 50:
		T50f15(ac, C, a1);
		break;
	case 51:
		T51f15(ac, C, a1);
		break;
	case 52:
		T52f15(ac, C, a1);
		break;
	case 53:
		T53f15(ac, C, a1);
		break;
	case 54:
		T54f15(ac, C, a1);
		break;
	case 55:
		T55f15(ac, C, a1);
		break;
	case 56:
		T56f15(ac, C, a1);
		break;
	case 57:
		T57f15(ac, C, a1);
		break;
	case 58:
		T58f15(ac, C, a1);
		break;
	case 59:
		T59f15(ac, C, a1);
		break;
	case 60:
		T60f15(ac, C, a1);
		break;
	case 61:
		T61f15(ac, C, a1);
		break;
	case 62:
		T62f15(ac, C, a1);
		break;
	case 63:
		T63f15(ac, C, a1);
		break;
	case 64:
		T64f15(ac, C, a1);
		break;
	}
}

/* Call to EXCEPTION.set_description */
void T22x4669469T0(TC* ac, T0* C, T0* a1)
{
	switch (((T0*)(C))->id) {
	case 33:
		T33f14(ac, C, a1);
		break;
	case 35:
		T35f18(ac, C, a1);
		break;
	case 37:
		T37f14(ac, C, a1);
		break;
	case 39:
		T39f16(ac, C, a1);
		break;
	case 40:
		T40f16(ac, C, a1);
		break;
	case 41:
		T41f16(ac, C, a1);
		break;
	case 42:
		T42f18(ac, C, a1);
		break;
	case 43:
		T43f16(ac, C, a1);
		break;
	case 44:
		T44f22(ac, C, a1);
		break;
	case 45:
		T45f16(ac, C, a1);
		break;
	case 48:
		T48f14(ac, C, a1);
		break;
	case 49:
		T49f14(ac, C, a1);
		break;
	case 50:
		T50f14(ac, C, a1);
		break;
	case 51:
		T51f14(ac, C, a1);
		break;
	case 52:
		T52f14(ac, C, a1);
		break;
	case 53:
		T53f14(ac, C, a1);
		break;
	case 54:
		T54f14(ac, C, a1);
		break;
	case 55:
		T55f14(ac, C, a1);
		break;
	case 56:
		T56f14(ac, C, a1);
		break;
	case 57:
		T57f14(ac, C, a1);
		break;
	case 58:
		T58f14(ac, C, a1);
		break;
	case 59:
		T59f14(ac, C, a1);
		break;
	case 60:
		T60f14(ac, C, a1);
		break;
	case 61:
		T61f14(ac, C, a1);
		break;
	case 62:
		T62f14(ac, C, a1);
		break;
	case 63:
		T63f14(ac, C, a1);
		break;
	case 64:
		T64f14(ac, C, a1);
		break;
	}
}

/* Call to EXCEPTION.set_exception_trace */
void T22x4669463T0(TC* ac, T0* C, T0* a1)
{
	switch (((T0*)(C))->id) {
	case 33:
		T33f13(ac, C, a1);
		break;
	case 35:
		T35f17(ac, C, a1);
		break;
	case 37:
		T37f13(ac, C, a1);
		break;
	case 39:
		T39f13(ac, C, a1);
		break;
	case 40:
		T40f15(ac, C, a1);
		break;
	case 41:
		T41f15(ac, C, a1);
		break;
	case 42:
		T42f17(ac, C, a1);
		break;
	case 43:
		T43f15(ac, C, a1);
		break;
	case 44:
		T44f21(ac, C, a1);
		break;
	case 45:
		T45f15(ac, C, a1);
		break;
	case 48:
		T48f13(ac, C, a1);
		break;
	case 49:
		T49f13(ac, C, a1);
		break;
	case 50:
		T50f13(ac, C, a1);
		break;
	case 51:
		T51f13(ac, C, a1);
		break;
	case 52:
		T52f13(ac, C, a1);
		break;
	case 53:
		T53f13(ac, C, a1);
		break;
	case 54:
		T54f13(ac, C, a1);
		break;
	case 55:
		T55f13(ac, C, a1);
		break;
	case 56:
		T56f13(ac, C, a1);
		break;
	case 57:
		T57f13(ac, C, a1);
		break;
	case 58:
		T58f13(ac, C, a1);
		break;
	case 59:
		T59f13(ac, C, a1);
		break;
	case 60:
		T60f13(ac, C, a1);
		break;
	case 61:
		T61f13(ac, C, a1);
		break;
	case 62:
		T62f13(ac, C, a1);
		break;
	case 63:
		T63f13(ac, C, a1);
		break;
	case 64:
		T64f13(ac, C, a1);
		break;
	}
}

/* Call to EXCEPTION.set_throwing_exception */
void T22x4669468T0(TC* ac, T0* C, T0* a1)
{
	switch (((T0*)(C))->id) {
	case 33:
		T33f12(ac, C, a1);
		break;
	case 35:
		T35f16(ac, C, a1);
		break;
	case 37:
		T37f12(ac, C, a1);
		break;
	case 39:
		T39f15(ac, C, a1);
		break;
	case 40:
		T40f13(ac, C, a1);
		break;
	case 41:
		T41f13(ac, C, a1);
		break;
	case 42:
		T42f15(ac, C, a1);
		break;
	case 43:
		T43f13(ac, C, a1);
		break;
	case 44:
		T44f18(ac, C, a1);
		break;
	case 45:
		T45f14(ac, C, a1);
		break;
	case 48:
		T48f12(ac, C, a1);
		break;
	case 49:
		T49f12(ac, C, a1);
		break;
	case 50:
		T50f12(ac, C, a1);
		break;
	case 51:
		T51f12(ac, C, a1);
		break;
	case 52:
		T52f12(ac, C, a1);
		break;
	case 53:
		T53f12(ac, C, a1);
		break;
	case 54:
		T54f12(ac, C, a1);
		break;
	case 55:
		T55f12(ac, C, a1);
		break;
	case 56:
		T56f12(ac, C, a1);
		break;
	case 57:
		T57f12(ac, C, a1);
		break;
	case 58:
		T58f12(ac, C, a1);
		break;
	case 59:
		T59f12(ac, C, a1);
		break;
	case 60:
		T60f12(ac, C, a1);
		break;
	case 61:
		T61f12(ac, C, a1);
		break;
	case 62:
		T62f12(ac, C, a1);
		break;
	case 63:
		T63f12(ac, C, a1);
		break;
	case 64:
		T64f12(ac, C, a1);
		break;
	}
}

T0* GE_mt32(TC* ac, T6 a1, T6 a2, T6 a3, T0* a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T6 a10, T1 a11)
{
	T0* R;
	R = GE_new32(ac, EIF_TRUE);
	((T32*)(R))->z1 = a1;
	((T32*)(R))->z2 = a2;
	((T32*)(R))->z3 = a3;
	((T32*)(R))->z4 = a4;
	((T32*)(R))->z5 = a5;
	((T32*)(R))->z6 = a6;
	((T32*)(R))->z7 = a7;
	((T32*)(R))->z8 = a8;
	((T32*)(R))->z9 = a9;
	((T32*)(R))->z10 = a10;
	((T32*)(R))->z11 = a11;
	return R;
}


void GE_init_const1()
{
}

void GE_init_const()
{
	GE_init_const1();
}

EIF_TYPE_OBJ GE_types[104][2] = {
{{0, 0, 0, EIF_FALSE, 0, 0, 0},{0, 0, 0, EIF_FALSE, 0, 0, 0}},
{{0, 0, 1, EIF_FALSE, 0, 0, 0},{0, 0, 65537, EIF_FALSE, 0, 0, 0}},
{{0, 0, 2, EIF_FALSE, 0, 0, 0},{0, 0, 65538, EIF_FALSE, 0, 0, 0}},
{{0, 0, 3, EIF_FALSE, 0, 0, 0},{0, 0, 65539, EIF_FALSE, 0, 0, 0}},
{{0, 0, 4, EIF_FALSE, 0, 0, 0},{0, 0, 65540, EIF_FALSE, 0, 0, 0}},
{{0, 0, 5, EIF_FALSE, 0, 0, 0},{0, 0, 65541, EIF_FALSE, 0, 0, 0}},
{{0, 0, 6, EIF_FALSE, 0, 0, 0},{0, 0, 65542, EIF_FALSE, 0, 0, 0}},
{{0, 0, 7, EIF_FALSE, 0, 0, 0},{0, 0, 65543, EIF_FALSE, 0, 0, 0}},
{{0, 0, 8, EIF_FALSE, 0, 0, 0},{0, 0, 65544, EIF_FALSE, 0, 0, 0}},
{{0, 0, 9, EIF_FALSE, 0, 0, 0},{0, 0, 65545, EIF_FALSE, 0, 0, 0}},
{{0, 0, 10, EIF_FALSE, 0, 0, 0},{0, 0, 65546, EIF_FALSE, 0, 0, 0}},
{{0, 0, 11, EIF_FALSE, 0, 0, 0},{0, 0, 65547, EIF_FALSE, 0, 0, 0}},
{{0, 0, 12, EIF_FALSE, 0, 0, 0},{0, 0, 65548, EIF_FALSE, 0, 0, 0}},
{{0, 0, 13, EIF_FALSE, 0, 0, 0},{0, 0, 65549, EIF_FALSE, 0, 0, 0}},
{{0, 0, 14, EIF_FALSE, 0, 0, 0},{0, 0, 65550, EIF_FALSE, 0, 0, 0}},
{{0, 0, 15, EIF_TRUE, 0, 0, 0},{0, 0, 65551, EIF_TRUE, 0, 0, 0}},
{{0, 0, 16, EIF_TRUE, 0, 0, 0},{0, 0, 65552, EIF_TRUE, 0, 0, 0}},
{{0, 0, 17, EIF_FALSE, 0, 0, 0},{0, 0, 65553, EIF_FALSE, 0, 0, 0}},
{{0, 0, 18, EIF_FALSE, 0, 0, 0},{0, 0, 65554, EIF_FALSE, 0, 0, 0}},
{{0, 0, 19, EIF_FALSE, 0, 0, 0},{0, 0, 65555, EIF_FALSE, 0, 0, 0}},
{{0, 0, 20, EIF_FALSE, 0, 0, 0},{0, 0, 65556, EIF_FALSE, 0, 0, 0}},
{{0, 0, 21, EIF_FALSE, 0, 0, 0},{0, 0, 65557, EIF_FALSE, 0, 0, 0}},
{{70, 0, 22, EIF_FALSE, 0, 0, 0},{0, 0, 65558, EIF_FALSE, 0, 0, 0}},
{{0, 0, 23, EIF_FALSE, 0, 0, 0},{24, 0, 65559, EIF_FALSE, 0, 0, 0}},
{{0, 0, 24, EIF_FALSE, 0, 0, 0},{0, 0, 65560, EIF_FALSE, 0, 0, 0}},
{{0, 0, 25, EIF_FALSE, 0, 0, 0},{0, 0, 65561, EIF_FALSE, 0, 0, 0}},
{{0, 0, 26, EIF_FALSE, 0, 0, 0},{0, 0, 65562, EIF_FALSE, 0, 0, 0}},
{{0, 0, 27, EIF_FALSE, 0, 0, 0},{0, 0, 65563, EIF_FALSE, 0, 0, 0}},
{{0, 0, 28, EIF_FALSE, 0, 0, 0},{0, 0, 65564, EIF_FALSE, 0, 0, 0}},
{{0, 0, 29, EIF_FALSE, 0, 0, 0},{0, 0, 65565, EIF_FALSE, 0, 0, 0}},
{{0, 0, 30, EIF_FALSE, 0, 0, 0},{0, 0, 65566, EIF_FALSE, 0, 0, 0}},
{{0, 0, 31, EIF_FALSE, 0, 0, 0},{0, 0, 65567, EIF_FALSE, 0, 0, 0}},
{{0, 0, 32, EIF_FALSE, 0, 0, 0},{0, 0, 65568, EIF_FALSE, 0, 0, 0}},
{{69, 0, 33, EIF_FALSE, 0, 0, 0},{34, 0, 65569, EIF_FALSE, 0, 0, 0}},
{{0, 0, 34, EIF_FALSE, 0, 0, 0},{0, 0, 65570, EIF_FALSE, 0, 0, 0}},
{{74, 0, 35, EIF_FALSE, 0, 0, 0},{36, 0, 65571, EIF_FALSE, 0, 0, 0}},
{{0, 0, 36, EIF_FALSE, 0, 0, 0},{0, 0, 65572, EIF_FALSE, 0, 0, 0}},
{{75, 0, 37, EIF_FALSE, 0, 0, 0},{38, 0, 65573, EIF_FALSE, 0, 0, 0}},
{{0, 0, 38, EIF_FALSE, 0, 0, 0},{0, 0, 65574, EIF_FALSE, 0, 0, 0}},
{{76, 0, 39, EIF_FALSE, 0, 0, 0},{0, 0, 65575, EIF_FALSE, 0, 0, 0}},
{{77, 0, 40, EIF_FALSE, 0, 0, 0},{0, 0, 65576, EIF_FALSE, 0, 0, 0}},
{{78, 0, 41, EIF_FALSE, 0, 0, 0},{0, 0, 65577, EIF_FALSE, 0, 0, 0}},
{{79, 0, 42, EIF_FALSE, 0, 0, 0},{0, 0, 65578, EIF_FALSE, 0, 0, 0}},
{{80, 0, 43, EIF_FALSE, 0, 0, 0},{0, 0, 65579, EIF_FALSE, 0, 0, 0}},
{{81, 0, 44, EIF_FALSE, 0, 0, 0},{0, 0, 65580, EIF_FALSE, 0, 0, 0}},
{{82, 0, 45, EIF_FALSE, 0, 0, 0},{0, 0, 65581, EIF_FALSE, 0, 0, 0}},
{{0, 0, 46, EIF_FALSE, 0, 0, 0},{0, 0, 65582, EIF_FALSE, 0, 0, 0}},
{{0, 0, 47, EIF_FALSE, 0, 0, 0},{0, 0, 65583, EIF_FALSE, 0, 0, 0}},
{{83, 0, 48, EIF_FALSE, 0, 0, 0},{0, 0, 65584, EIF_FALSE, 0, 0, 0}},
{{84, 0, 49, EIF_FALSE, 0, 0, 0},{0, 0, 65585, EIF_FALSE, 0, 0, 0}},
{{85, 0, 50, EIF_FALSE, 0, 0, 0},{0, 0, 65586, EIF_FALSE, 0, 0, 0}},
{{86, 0, 51, EIF_FALSE, 0, 0, 0},{0, 0, 65587, EIF_FALSE, 0, 0, 0}},
{{87, 0, 52, EIF_FALSE, 0, 0, 0},{0, 0, 65588, EIF_FALSE, 0, 0, 0}},
{{88, 0, 53, EIF_FALSE, 0, 0, 0},{0, 0, 65589, EIF_FALSE, 0, 0, 0}},
{{89, 0, 54, EIF_FALSE, 0, 0, 0},{0, 0, 65590, EIF_FALSE, 0, 0, 0}},
{{90, 0, 55, EIF_FALSE, 0, 0, 0},{0, 0, 65591, EIF_FALSE, 0, 0, 0}},
{{91, 0, 56, EIF_FALSE, 0, 0, 0},{0, 0, 65592, EIF_FALSE, 0, 0, 0}},
{{92, 0, 57, EIF_FALSE, 0, 0, 0},{0, 0, 65593, EIF_FALSE, 0, 0, 0}},
{{93, 0, 58, EIF_FALSE, 0, 0, 0},{0, 0, 65594, EIF_FALSE, 0, 0, 0}},
{{94, 0, 59, EIF_FALSE, 0, 0, 0},{0, 0, 65595, EIF_FALSE, 0, 0, 0}},
{{95, 0, 60, EIF_FALSE, 0, 0, 0},{0, 0, 65596, EIF_FALSE, 0, 0, 0}},
{{96, 0, 61, EIF_FALSE, 0, 0, 0},{0, 0, 65597, EIF_FALSE, 0, 0, 0}},
{{97, 0, 62, EIF_FALSE, 0, 0, 0},{0, 0, 65598, EIF_FALSE, 0, 0, 0}},
{{98, 0, 63, EIF_FALSE, 0, 0, 0},{0, 0, 65599, EIF_FALSE, 0, 0, 0}},
{{99, 0, 64, EIF_FALSE, 0, 0, 0},{0, 0, 65600, EIF_FALSE, 0, 0, 0}},
{{0, 0, 65, EIF_FALSE, 0, 0, 0},{0, 0, 65601, EIF_FALSE, 0, 0, 0}},
{{0, 0, 66, EIF_TRUE, 0, 0, 0},{0, 0, 65602, EIF_TRUE, 0, 0, 0}},
{{0, 0, 67, EIF_TRUE, 0, 0, 0},{0, 0, 65603, EIF_TRUE, 0, 0, 0}},
{{0, 0, 68, EIF_FALSE, 0, 0, 0},{0, 0, 65604, EIF_FALSE, 0, 0, 0}},
{{0, 0, 69, EIF_FALSE, 0, 0, 0},{0, 0, 65605, EIF_FALSE, 0, 0, 0}},
{{0, 0, 70, EIF_FALSE, 0, 0, 0},{0, 0, 65606, EIF_FALSE, 0, 0, 0}},
{{0, 0, 71, EIF_FALSE, 0, 0, 0},{0, 0, 65607, EIF_FALSE, 0, 0, 0}},
{{0, 0, 72, EIF_FALSE, 0, 0, 0},{0, 0, 65608, EIF_FALSE, 0, 0, 0}},
{{0, 0, 73, EIF_FALSE, &T73f6, 0, 0},{0, 0, 65609, EIF_FALSE, &T73f6, 0, 0}},
{{0, 0, 74, EIF_FALSE, 0, 0, 0},{0, 0, 65610, EIF_FALSE, 0, 0, 0}},
{{0, 0, 75, EIF_FALSE, 0, 0, 0},{0, 0, 65611, EIF_FALSE, 0, 0, 0}},
{{0, 0, 76, EIF_FALSE, 0, 0, 0},{0, 0, 65612, EIF_FALSE, 0, 0, 0}},
{{0, 0, 77, EIF_FALSE, 0, 0, 0},{0, 0, 65613, EIF_FALSE, 0, 0, 0}},
{{0, 0, 78, EIF_FALSE, 0, 0, 0},{0, 0, 65614, EIF_FALSE, 0, 0, 0}},
{{0, 0, 79, EIF_FALSE, 0, 0, 0},{0, 0, 65615, EIF_FALSE, 0, 0, 0}},
{{0, 0, 80, EIF_FALSE, 0, 0, 0},{0, 0, 65616, EIF_FALSE, 0, 0, 0}},
{{0, 0, 81, EIF_FALSE, 0, 0, 0},{0, 0, 65617, EIF_FALSE, 0, 0, 0}},
{{0, 0, 82, EIF_FALSE, 0, 0, 0},{0, 0, 65618, EIF_FALSE, 0, 0, 0}},
{{0, 0, 83, EIF_FALSE, 0, 0, 0},{0, 0, 65619, EIF_FALSE, 0, 0, 0}},
{{0, 0, 84, EIF_FALSE, 0, 0, 0},{0, 0, 65620, EIF_FALSE, 0, 0, 0}},
{{0, 0, 85, EIF_FALSE, 0, 0, 0},{0, 0, 65621, EIF_FALSE, 0, 0, 0}},
{{0, 0, 86, EIF_FALSE, 0, 0, 0},{0, 0, 65622, EIF_FALSE, 0, 0, 0}},
{{0, 0, 87, EIF_FALSE, 0, 0, 0},{0, 0, 65623, EIF_FALSE, 0, 0, 0}},
{{0, 0, 88, EIF_FALSE, 0, 0, 0},{0, 0, 65624, EIF_FALSE, 0, 0, 0}},
{{0, 0, 89, EIF_FALSE, 0, 0, 0},{0, 0, 65625, EIF_FALSE, 0, 0, 0}},
{{0, 0, 90, EIF_FALSE, 0, 0, 0},{0, 0, 65626, EIF_FALSE, 0, 0, 0}},
{{0, 0, 91, EIF_FALSE, 0, 0, 0},{0, 0, 65627, EIF_FALSE, 0, 0, 0}},
{{0, 0, 92, EIF_FALSE, 0, 0, 0},{0, 0, 65628, EIF_FALSE, 0, 0, 0}},
{{0, 0, 93, EIF_FALSE, 0, 0, 0},{0, 0, 65629, EIF_FALSE, 0, 0, 0}},
{{0, 0, 94, EIF_FALSE, 0, 0, 0},{0, 0, 65630, EIF_FALSE, 0, 0, 0}},
{{0, 0, 95, EIF_FALSE, 0, 0, 0},{0, 0, 65631, EIF_FALSE, 0, 0, 0}},
{{0, 0, 96, EIF_FALSE, 0, 0, 0},{0, 0, 65632, EIF_FALSE, 0, 0, 0}},
{{0, 0, 97, EIF_FALSE, 0, 0, 0},{0, 0, 65633, EIF_FALSE, 0, 0, 0}},
{{0, 0, 98, EIF_FALSE, 0, 0, 0},{0, 0, 65634, EIF_FALSE, 0, 0, 0}},
{{0, 0, 99, EIF_FALSE, 0, 0, 0},{0, 0, 65635, EIF_FALSE, 0, 0, 0}},
{{0, 0, 100, EIF_FALSE, 0, 0, 0},{0, 0, 65636, EIF_FALSE, 0, 0, 0}},
{{0, 0, 101, EIF_FALSE, 0, 0, 0},{0, 0, 65637, EIF_FALSE, 0, 0, 0}},
{{0, 0, 102, EIF_FALSE, 0, 0, 0},{0, 0, 65638, EIF_FALSE, 0, 0, 0}},
{{0, 0, 103, EIF_FALSE, 0, 0, 0},{0, 0, 65639, EIF_FALSE, 0, 0, 0}}
};


GE_type_info GE_type_infos[104] = {
{0, 0, 0, 0},
{1, GE_TYPE_FLAG_BOOLEAN|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new1, 0},
{2, GE_TYPE_FLAG_CHARACTER_8|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new2, 0},
{3, GE_TYPE_FLAG_CHARACTER_32|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new3, 0},
{4, GE_TYPE_FLAG_INTEGER_8|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new4, 0},
{5, GE_TYPE_FLAG_INTEGER_16|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new5, 0},
{6, GE_TYPE_FLAG_INTEGER_32|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new6, 0},
{7, GE_TYPE_FLAG_INTEGER_64|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new7, 0},
{8, GE_TYPE_FLAG_NATURAL_8|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new8, 0},
{9, GE_TYPE_FLAG_NATURAL_16|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new9, 0},
{10, GE_TYPE_FLAG_NATURAL_32|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new10, 0},
{11, GE_TYPE_FLAG_NATURAL_64|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new11, 0},
{12, GE_TYPE_FLAG_REAL_32|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new12, 0},
{13, GE_TYPE_FLAG_REAL_64|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new13, 0},
{14, GE_TYPE_FLAG_POINTER|GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new14, 0},
{15, GE_TYPE_FLAG_SPECIAL, (EIF_REFERENCE (*)())&GE_new15, 0},
{16, GE_TYPE_FLAG_SPECIAL, 0, 0},
{17, 0, (EIF_REFERENCE (*)())&GE_new17, 0},
{18, 0, 0, 0},
{19, 0, 0, 0},
{20, 0, 0, 0},
{21, 0, (EIF_REFERENCE (*)())&GE_new21, 0},
{22, 0, 0, 0},
{23, GE_TYPE_FLAG_NONE, 0, 0},
{24, 0, 0, 0},
{25, 0, 0, 0},
{26, 0, (EIF_REFERENCE (*)())&GE_new26, 0},
{27, 0, (EIF_REFERENCE (*)())&GE_new27, 0},
{28, 0, (EIF_REFERENCE (*)())&GE_new28, 0},
{29, 0, (EIF_REFERENCE (*)())&GE_new29, 0},
{30, 0, (EIF_REFERENCE (*)())&GE_new30, 0},
{31, 0, (EIF_REFERENCE (*)())&GE_new31, 0},
{32, GE_TYPE_FLAG_TUPLE, (EIF_REFERENCE (*)())&GE_new32, 0},
{33, 0, (EIF_REFERENCE (*)())&GE_new33, 0},
{34, 0, 0, 0},
{35, 0, (EIF_REFERENCE (*)())&GE_new35, 0},
{36, 0, 0, 0},
{37, 0, (EIF_REFERENCE (*)())&GE_new37, 0},
{38, 0, 0, 0},
{39, 0, (EIF_REFERENCE (*)())&GE_new39, 0},
{40, 0, (EIF_REFERENCE (*)())&GE_new40, 0},
{41, 0, (EIF_REFERENCE (*)())&GE_new41, 0},
{42, 0, (EIF_REFERENCE (*)())&GE_new42, 0},
{43, 0, (EIF_REFERENCE (*)())&GE_new43, 0},
{44, 0, (EIF_REFERENCE (*)())&GE_new44, 0},
{45, 0, (EIF_REFERENCE (*)())&GE_new45, 0},
{46, 0, 0, 0},
{47, GE_TYPE_FLAG_DEFERRED, 0, 0},
{48, 0, (EIF_REFERENCE (*)())&GE_new48, 0},
{49, 0, (EIF_REFERENCE (*)())&GE_new49, 0},
{50, 0, (EIF_REFERENCE (*)())&GE_new50, 0},
{51, 0, (EIF_REFERENCE (*)())&GE_new51, 0},
{52, 0, (EIF_REFERENCE (*)())&GE_new52, 0},
{53, 0, (EIF_REFERENCE (*)())&GE_new53, 0},
{54, 0, (EIF_REFERENCE (*)())&GE_new54, 0},
{55, 0, (EIF_REFERENCE (*)())&GE_new55, 0},
{56, 0, (EIF_REFERENCE (*)())&GE_new56, 0},
{57, 0, (EIF_REFERENCE (*)())&GE_new57, 0},
{58, 0, (EIF_REFERENCE (*)())&GE_new58, 0},
{59, 0, (EIF_REFERENCE (*)())&GE_new59, 0},
{60, 0, (EIF_REFERENCE (*)())&GE_new60, 0},
{61, 0, (EIF_REFERENCE (*)())&GE_new61, 0},
{62, 0, (EIF_REFERENCE (*)())&GE_new62, 0},
{63, 0, (EIF_REFERENCE (*)())&GE_new63, 0},
{64, 0, (EIF_REFERENCE (*)())&GE_new64, 0},
{65, 0, (EIF_REFERENCE (*)())&GE_new65, 0},
{66, GE_TYPE_FLAG_SPECIAL, (EIF_REFERENCE (*)())&GE_new66, 0},
{67, GE_TYPE_FLAG_SPECIAL, (EIF_REFERENCE (*)())&GE_new67, 0},
{68, 0, 0, 0},
{69, 0, 0, 0},
{70, 0, 0, 0},
{71, GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new71, 0},
{72, 0, (EIF_REFERENCE (*)())&GE_new72, 0},
{73, 0, (EIF_REFERENCE (*)())&GE_new73, &T73f6},
{74, 0, 0, 0},
{75, 0, 0, 0},
{76, 0, 0, 0},
{77, 0, 0, 0},
{78, 0, 0, 0},
{79, 0, 0, 0},
{80, 0, 0, 0},
{81, 0, 0, 0},
{82, 0, 0, 0},
{83, 0, 0, 0},
{84, 0, 0, 0},
{85, 0, 0, 0},
{86, 0, 0, 0},
{87, 0, 0, 0},
{88, 0, 0, 0},
{89, 0, 0, 0},
{90, 0, 0, 0},
{91, 0, 0, 0},
{92, 0, 0, 0},
{93, 0, 0, 0},
{94, 0, 0, 0},
{95, 0, 0, 0},
{96, 0, 0, 0},
{97, 0, 0, 0},
{98, 0, 0, 0},
{99, 0, 0, 0},
{100, GE_TYPE_FLAG_DEFERRED, 0, 0},
{101, 0, (EIF_REFERENCE (*)())&GE_new101, 0},
{102, GE_TYPE_FLAG_EXPANDED, (EIF_REFERENCE (*)())&GE_new102, 0},
{103, 0, 0, 0}
};

int GE_main(int argc, EIF_NATIVE_CHAR** argv)
{
	T0* t1;
	GE_call tc = {"SENSOR_UMIDADE","root's creation",0};
	TC* ac = GE_new_context(0);
	ac->call = &tc;
	GE_type_info_count = 103;
	GE_argc = argc;
	GE_argv = argv;
	GE_main_context = ac;
	GE_system_name = "sensor_umidade";
	GE_root_class_name = "SENSOR_UMIDADE";
	GE_new_exception_manager = &GE_new21;
	GE_init_exception_manager = &T21s14;
	GE_last_exception = &T21s1;
	GE_once_raise = &T21s15;
	GE_set_exception_data = &T21s16;
	GE_init_onces(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0);
	GE_init_exception(ac);
	GE_init_console();
	GE_init_identified();
	GE_init_const();
	t1 = T26c2(ac);
	return 0;
}


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to manipulate strings"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_STRING_C
#define GE_STRING_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_STRING_H
#include "ge_string.h"
#endif
#ifndef GE_NATIVE_STRING_H
#include "ge_native_string.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Number of EIF_CHARACTER_32 characters which can be read from
 * the first `n' native characters in native string `s'.
 * Invalid native characters are escaped.
 */
static int GE_nstr_str32len(EIF_NATIVE_CHAR* s, EIF_INTEGER n)
{
	int i, j;
#ifdef EIF_WINDOWS
	uint16_t c1, c2;
#else
	uint8_t c1, c2, c3, c4;
#endif

	j = 0;
	for (i = 0; i < n; i++) {
#ifdef EIF_WINDOWS
		c1 = (uint16_t)s[i];
		if (c1 == 0) {
			return j;
		} else if (c1 < 0xD800 || c1 >= 0xE000) {
				/* Codepoint from Basic Multilingual Plane: one 16-bit code unit. */
			j++;
		} else if (c1 <= 0xDBFF && i + 1 < n) {
				/* Check if a lead surrogate (value between 0xD800 and 0xDBFF) is followed by a trail surrogate. */
			c2 = (uint16_t)s[i + 1];
			if (c2 >= 0xDC00 && c2 <= 0xDFFF) {
				/* Supplementary Planes: surrogate pair with lead and trail surrogates. */
				i++;
				j++;
			} else {
				j += 6;
			}
		} else {
			j += 6;
		}
#else
		c1 = (uint8_t)s[i];
		if (c1 == 0) {
			return j;
		} else if (c1 <= 0x7F) {
			j++;
		} else if ((c1 & 0xE0) == 0xC0) {
			if (i + 1 < n) {
				c2 = (uint8_t)s[i + 1];
				if ((c2 & 0xC0) == 0x80) {
					j++;
					i++;
				} else {
					j += 3;
				}
			} else {
				j += 3;
			}
		} else if ((c1 & 0xF0) == 0xE0) {
			if (i + 2 < n) {
				c2 = (uint8_t)s[i + 1];
				c3 = (uint8_t)s[i + 2];
				if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80) {
					j++;
					i +=2;
				} else {
					j += 3;
				}
			} else {
				j += 3;
			}
		} else if ((c1 & 0xF8) == 0xF0) {
			if (i + 3 < n) {
				c2 = (uint8_t)s[i + 1];
				c3 = (uint8_t)s[i + 2];
				c4 = (uint8_t)s[i + 3];
				if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80 && (c4 & 0xC0) == 0x80) {
					j++;
					i +=3;
				} else {
					j += 3;
				}
			} else {
				j += 3;
			}
		} else {
			j += 3;
		}
#endif
	}
	return j;
}

/*
 * Hexadecimal representation of `a_code'.
 * `a_code' is expected to be between 0 and 15.
 */
static char GE_to_hex(uint16_t a_code)
{
	switch (a_code) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	default:
		return 'F';
	}
}

/*
 * Copy escaped version of `c' to `a_buffer'.
 * `a_buffer' is expected to have enough space for 6 characters.
 */
static void GE_uint16_to_escaped_str32(uint16_t c, EIF_CHARACTER_32* a_buffer)
{
	int i = 0;

	a_buffer[i] = (EIF_CHARACTER_32)0x0000FFFD;
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)'u';
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex((c & 0xF000) >> 12);
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex((c & 0x0F00) >> 8);
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex((c & 0x00F0) >> 4);
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex(c & 0x000F);
}

#ifndef __LCC__
/* lcc-win32 complains about this used static function. */

/*
 * Copy escaped version of `c' to `a_buffer'.
 * `a_buffer' is expected to have enough space for 3 characters.
 */
static void GE_uint8_to_escaped_str32(uint8_t c, EIF_CHARACTER_32* a_buffer)
{
	int i = 0;

	a_buffer[i] = (EIF_CHARACTER_32)0x0000FFFD;
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex((uint16_t)((c & 0xF0) >> 4));
	i++;
	a_buffer[i] = (EIF_CHARACTER_32)GE_to_hex((uint16_t)(c & 0x0F));
}
#endif

/*
 * Copy to `a_buffer' the EIF_CHARACTER_32 characters corresponding to the
 * first `n' native characters in the native string `s'.
 * `a_buffer' is expected to have enough space.
 * Invalid native characters are escaped.
 */
static void GE_nstr_to_str32(EIF_NATIVE_CHAR* s, EIF_CHARACTER_32* a_buffer, EIF_INTEGER n)
{
	int i, j;
#ifdef EIF_WINDOWS
	uint16_t c1, c2;
#else
	uint8_t c1, c2, c3, c4;
#endif

	j = 0;
	for (i = 0; i < n; i++) {
#ifdef EIF_WINDOWS
		c1 = (uint16_t)s[i];
		if (c1 < 0xD800 || c1 >= 0xE000) {
				/* Codepoint from Basic Multilingual Plane: one 16-bit code unit. */
			a_buffer[j] = (EIF_CHARACTER_32)(c1);
			j++;
		} else if (c1 <= 0xDBFF && i + 1 < n) {
				/* Check if a lead surrogate (value between 0xD800 and 0xDBFF) is followed by a trail surrogate. */
			c2 = (uint16_t)s[i + 1];
			if (c2 >= 0xDC00 && c2 <= 0xDFFF) {
					/* Supplementary Planes: surrogate pair with lead and trail surrogates. */
				a_buffer[j] = (EIF_CHARACTER_32)(((uint32_t)c1 << 10) + (uint32_t)c2 - 0x035FDC00);
				j++;
				i++;
			} else {
				GE_uint16_to_escaped_str32(c1, a_buffer + j);
				j += 6;
			}
		} else {
			GE_uint16_to_escaped_str32(c1, a_buffer + j);
			j += 6;
		}
#else
		c1 = (uint8_t)s[i];
		if (c1 <= 0x7F) {
			a_buffer[j] = (EIF_CHARACTER_32)(c1);
			j++;
		} else if ((c1 & 0xE0) == 0xC0) {
			if (i + 1 < n) {
				c2 = (uint8_t)s[i + 1];
				if ((c2 & 0xC0) == 0x80) {
					a_buffer[j] = (EIF_CHARACTER_32)((((uint32_t)c1 & 0x0000001F) << 6) | ((uint32_t)c2 & 0x0000003F));
					j++;
					i++;
				} else {
					GE_uint8_to_escaped_str32(c1, a_buffer + j);
					j += 3;
				}
			} else {
				GE_uint8_to_escaped_str32(c1, a_buffer + j);
				j += 3;
			}
		} else if ((c1 & 0xF0) == 0xE0) {
			if (i + 2 < n) {
				c2 = (uint8_t)s[i + 1];
				c3 = (uint8_t)s[i + 2];
				if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80) {
					a_buffer[j] = (EIF_CHARACTER_32)((((uint32_t)c1 & 0x0000000F) << 12) | (((uint32_t)c2 & 0x0000003F) << 6) | ((uint32_t)c3 & 0x0000003F));
					j++;
					i +=2;
				} else {
					GE_uint8_to_escaped_str32(c1, a_buffer + j);
					j += 3;
				}
			} else {
				GE_uint8_to_escaped_str32(c1, a_buffer + j);
				j += 3;
			}
		} else if ((c1 & 0xF8) == 0xF0) {
			if (i + 3 < n) {
				c2 = (uint8_t)s[i + 1];
				c3 = (uint8_t)s[i + 2];
				c4 = (uint8_t)s[i + 3];
				if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80 && (c4 & 0xC0) == 0x80) {
					a_buffer[j] = (EIF_CHARACTER_32)((((uint32_t)c1 & 0x00000007) << 18) | (((uint32_t)c2 & 0x0000003F) << 12) | (((uint32_t)c3 & 0x0000003F) << 6) | ((uint32_t)c4 & 0x0000003F));
					j++;
					i +=3;
				} else {
					GE_uint8_to_escaped_str32(c1, a_buffer + j);
					j += 3;
				}
			} else {
				GE_uint8_to_escaped_str32(c1, a_buffer + j);
				j += 3;
			}
		} else {
			GE_uint8_to_escaped_str32(c1, a_buffer + j);
			j += 3;
		}
#endif
	}
}

/*
 * Copy to `a_buffer' the EIF_CHARACTER_32 characters corresponding to the
 * first `n' characters in the ISO 8859-1 string `s'.
 * `a_buffer' is expected to have enough space for `n' characters.
 */
static void GE_str8_to_str32(const char* s, EIF_CHARACTER_32* a_buffer, EIF_INTEGER n)
{
	int i;
	for (i = 0; i < n; i++) {
		a_buffer[i] = (EIF_CHARACTER_32)s[i];
	}
}

/*
 * New Eiffel string of type "STRING_8" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_ms8(const char* s, EIF_INTEGER c)
{
	EIF_STRING_8* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_8* l_area_base_address;

	l_string = (EIF_STRING_8*)GE_new_str8(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_8*)GE_sp8_base_address((EIF_REFERENCE)l_area);
	memcpy((char*)l_area_base_address, s, c);
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "STRING_8" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_str8(const char* s)
{
	return GE_ms8(s, strlen(s));
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_8" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_ims8(const char* s, EIF_INTEGER c)
{
	EIF_IMMUTABLE_STRING_8* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_8* l_area_base_address;

	l_string = (EIF_IMMUTABLE_STRING_8*)GE_new_istr8(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_8*)GE_sp8_base_address((EIF_REFERENCE)l_area);
	memcpy((char*)l_area_base_address, s, c);
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "STRING_32" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_ms32(const char* s, EIF_INTEGER c)
{
	EIF_STRING_32* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_32* l_area_base_address;

	l_string = (EIF_STRING_32*)GE_new_str32(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_32*)GE_sp32_base_address((EIF_REFERENCE)l_area);
	GE_str8_to_str32(s, l_area_base_address, c);
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "STRING_32" containing the
 * first `c' 32-bit characters built from `s' by reading
 * groups of four bytes with little-endian byte order.
 */
EIF_REFERENCE GE_ms32_from_utf32le(const char* s, EIF_INTEGER c)
{
	EIF_STRING_32* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_32* l_area_base_address;

	l_string = (EIF_STRING_32*)GE_new_str32(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_32*)GE_sp32_base_address((EIF_REFERENCE)l_area);
#if BYTEORDER == 0x1234
	memcpy((EIF_CHARACTER_32*)l_area_base_address, s, c * 4);
#else
	{
		int i;
		volatile EIF_CHARACTER_32 l_little;
		EIF_CHARACTER_32 l_big;
		for (i = 0; i < c ; i++) {
			memcpy(&l_little, s + (i * 4), 4);
				/* Convert our little endian to big endian. */
			l_big = ((l_little >> 24) & 0xFF) |
				((l_little >> 8) & 0xFF00) |
				((l_little << 8) & 0xFF0000) |
				((l_little << 24) & 0xFF000000);
			l_area_base_address[i] = l_big;
		}
	}
#endif
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "STRING_32" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_str32(const char* s)
{
	return GE_ms32(s, strlen(s));
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing
 * the first `c' characters found in ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_ims32(const char* s, EIF_INTEGER c)
{
	EIF_IMMUTABLE_STRING_32* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_32* l_area_base_address;

	l_string = (EIF_IMMUTABLE_STRING_32*)GE_new_istr32(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_32*)GE_sp32_base_address((EIF_REFERENCE)l_area);
	GE_str8_to_str32(s, l_area_base_address, c);
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing the
 * first `c' 32-bit characters built from `s' by reading
 * groups of four bytes with little-endian byte order.
 */
EIF_REFERENCE GE_ims32_from_utf32le(const char* s, EIF_INTEGER c)
{
	EIF_IMMUTABLE_STRING_32* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_32* l_area_base_address;

	l_string = (EIF_IMMUTABLE_STRING_32*)GE_new_istr32(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_32*)GE_sp32_base_address((EIF_REFERENCE)l_area);
#if BYTEORDER == 0x1234
	memcpy((EIF_CHARACTER_32*)l_area_base_address, s, c * 4);
#else
	{
		int i;
		volatile EIF_CHARACTER_32 l_little;
		EIF_CHARACTER_32 l_big;
		for (i = 0; i < c ; i++) {
			memcpy(&l_little, s + (i * 4), 4);
				/* Convert our little endian to big endian. */
			l_big = ((l_little >> 24) & 0xFF) |
				((l_little >> 8) & 0xFF00) |
				((l_little << 8) & 0xFF0000) |
				((l_little << 24) & 0xFF000000);
			l_area_base_address[i] = l_big;
		}
	}
#endif
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
EIF_REFERENCE GE_istr32(const char* s)
{
	return GE_ims32(s, strlen(s));
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing the
 * first `n' native characters found in native string `s'.
 * Invalid native characters are escaped.
 */
EIF_REFERENCE GE_ims32_from_nstr(EIF_NATIVE_CHAR* s, EIF_INTEGER n)
{
	EIF_IMMUTABLE_STRING_32* l_string;
	EIF_SPECIAL* l_area;
	EIF_CHARACTER_32* l_area_base_address;
	EIF_INTEGER c;

	c = GE_nstr_str32len(s, n);
	l_string = (EIF_IMMUTABLE_STRING_32*)GE_new_istr32(c);
	l_area = (EIF_SPECIAL*)(l_string->area);
	l_area_base_address = (EIF_CHARACTER_32*)GE_sp32_base_address((EIF_REFERENCE)l_area);
	GE_nstr_to_str32(s, l_area_base_address, n);
	/* Note that the area was calloc-ed, so not need to add a trailing null character. */
	l_area->count = (c + 1);
	l_string->count = c;
	return (EIF_REFERENCE)l_string;
}

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing all
 * characters found in the null-terminated native string `s'.
 * Invalid native characters are escaped.
 */
EIF_REFERENCE GE_istr32_from_nstr(EIF_NATIVE_CHAR* s)
{
	return GE_ims32_from_nstr(s, GE_nstrlen(s));
}

/*
 * New Eiffel string of type "STRING" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'
 */
EIF_REFERENCE GE_str(const char* s)
{
	return GE_ms(s, strlen(s));
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement type information"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_TYPES_C
#define GE_TYPES_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_TYPES_H
#include "ge_types.h"
#endif
#ifndef GE_STRING_H
#include "ge_string.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Number of type infos in `GE_type_infos'.
 * Do not take into account the fake item at index 0.
 */
int GE_type_info_count;

/*
 * Encode a EIF_TYPE into a EIF_ENCODED_TYPE.
 * The lower part of EIF_ENCODED_TYPE contains the .id field,
 * and the upper part the .annotations.
 */
EIF_ENCODED_TYPE GE_encoded_type(EIF_TYPE a_type)
{
	EIF_ENCODED_TYPE l_result;

#if defined(_MSC_VER)
		/* This code below is just optimized as one move by cl on x86 platforms.
		 * The else-part below generates non-optimal code with cl.
		 */
	memcpy((void*)&l_result, (void*)&a_type, sizeof(EIF_ENCODED_TYPE));
#else
		/* This code below is just optimized as one move by gcc/clang on x86 platforms. */
	l_result = a_type.annotations;
	l_result = (l_result << 16) | a_type.id;
#endif
	return l_result;
}

/*
 * Decode a EIF_ENCODED_TYPE into a EIF_TYPE.
 * The lower part of EIF_ENCODED_TYPE contains the .id field,
 * and the upper part the .annotations.
 */
EIF_TYPE GE_decoded_type(EIF_ENCODED_TYPE a_type)
{
	EIF_TYPE l_result;

#if defined(_MSC_VER)
		/* This code below is just optimized as one move by cl on x86 platforms.
		 * The else-part below generates non-optimal code with cl.
		 */
	memcpy((void*)&l_result, (void*)&a_type, sizeof(EIF_TYPE));
#else
		/* This code below is just optimized as one move by gcc/clang on x86 platforms. */
	l_result.id = a_type & 0x0000FFFF;
	l_result.annotations = a_type >> 16;
#endif
	return l_result;
}

/*
 * Type with `a_id' and `a_annotations'.
 */
EIF_TYPE GE_new_type(EIF_TYPE_INDEX a_id, EIF_TYPE_INDEX a_annotations)
{
	EIF_TYPE l_result;
	l_result.id = a_id;
	l_result.annotations = a_annotations;
	return l_result;
}

/*
 * Associated detachable type of `a_type' if any,
 * otherwise `a_type'.
 */
EIF_TYPE GE_non_attached_type(EIF_TYPE a_type)
{
		/* Since types are by default detachable, we simply remove
		 * all attachment marks. */
	a_type.annotations &= ~(ATTACHED_FLAG | DETACHABLE_FLAG);
	return a_type;
}

/*
 * Associated attached type of `a_type' if any,
 * otherwise `a_type'.
 */
EIF_TYPE GE_attached_type(EIF_TYPE a_type)
{
	if (!GE_is_expanded_type_index(a_type.id)) {
		a_type.annotations &= ~DETACHABLE_FLAG;
		a_type.annotations |= ATTACHED_FLAG;
	}
	return a_type;
}

/*
 * Is `a_type' a SPECIAL type of user-defined expanded type?
 */
EIF_BOOLEAN GE_is_special_of_expanded_type_index(EIF_TYPE_INDEX a_type)
{
	EIF_BOOLEAN l_result = EIF_FALSE;
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	EIF_TYPE_INDEX l_generic_parameter;
	uint32_t l_flags;

	if ((GE_type_infos[a_type].flags & GE_TYPE_FLAG_SPECIAL)) {
		l_generic_parameter = GE_decoded_type(GE_type_infos[a_type].generic_parameters[0]).id;
		l_flags = GE_type_infos[l_generic_parameter].flags;
		l_result = EIF_TEST((l_flags & GE_TYPE_FLAG_EXPANDED) && !(l_flags & GE_TYPE_FLAG_BASIC_MASK));
	}
#endif
	return l_result;
}

/*
 * Is `a_type' a SPECIAL type of reference type?
 */
EIF_BOOLEAN GE_is_special_of_reference_type_index(EIF_TYPE_INDEX a_type)
{
	EIF_BOOLEAN l_result = EIF_FALSE;
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	EIF_TYPE_INDEX l_generic_parameter;
	uint32_t l_flags;

	if ((GE_type_infos[a_type].flags & GE_TYPE_FLAG_SPECIAL)) {
		l_generic_parameter = GE_decoded_type(GE_type_infos[a_type].generic_parameters[0]).id;
		l_flags = GE_type_infos[l_generic_parameter].flags;
		l_result = EIF_TEST(!(l_flags & GE_TYPE_FLAG_EXPANDED));
	}
#endif
	return l_result;
}

/*
 * Is `a_type' a SPECIAL type of reference type or basic expanded type?
 * (Note that user-defined expanded types are excluded.)
 */
EIF_BOOLEAN GE_is_special_of_reference_or_basic_expanded_type_index(EIF_TYPE_INDEX a_type)
{
	EIF_BOOLEAN l_result = EIF_FALSE;
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	EIF_TYPE_INDEX l_generic_parameter;
	uint32_t l_flags;

	if ((GE_type_infos[a_type].flags & GE_TYPE_FLAG_SPECIAL)) {
		l_generic_parameter = GE_decoded_type(GE_type_infos[a_type].generic_parameters[0]).id;
		l_flags = GE_type_infos[l_generic_parameter].flags;
		l_result = EIF_TEST(!(l_flags & GE_TYPE_FLAG_EXPANDED) || (l_flags & GE_TYPE_FLAG_BASIC_MASK));
	}
#endif
	return l_result;
}

/*
 * Does `i'-th field of `a_object + a_physical_offset' (which is expected to be reference)
 * denote a reference with copy semantics?
 */
EIF_BOOLEAN GE_is_copy_semantics_field(EIF_INTEGER i, EIF_POINTER a_object, EIF_INTEGER a_physical_offset)
{
	EIF_REFERENCE l_object;

	l_object = GE_reference_field(i, a_object, a_physical_offset);
	if (l_object) {
		return GE_is_expanded_object(l_object);
	} else {
		return EIF_FALSE;
	}
}

/*
 * Does `i'-th item of special `a_object' (which is expected to be reference)
 * denote a reference with copy semantics?
 */
EIF_BOOLEAN GE_is_special_copy_semantics_item(EIF_INTEGER i, EIF_POINTER a_object)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_OFFSET)
	EIF_REFERENCE l_object;
	GE_type_info l_type_info;

	l_type_info = GE_type_infos[((EIF_REFERENCE)a_object)->id];
		/* The last pseudo attribute is the item at index 0 in the special object */
	l_object = *(EIF_REFERENCE*)((char*)a_object + l_type_info.attributes[l_type_info.attribute_count - 1]->offset + i * sizeof(EIF_REFERENCE));
	if (l_object) {
		return GE_is_expanded_object(l_object);
	} else {
		return EIF_FALSE;
	}
#else
	return EIF_FALSE;
#endif
}

/*
 * Generator class name of `a_type'.
 */
EIF_REFERENCE GE_generator_of_type_index(EIF_TYPE_INDEX a_type)
{
	const char* l_generator;
#ifdef GE_USE_TYPE_GENERATOR
/* TODO: check that `a_type' is valid. */
	l_generator = GE_type_infos[a_type].generator;
#else
	l_generator = "";
#endif
	return GE_str(l_generator);
}

EIF_REFERENCE GE_generator_8_of_type_index(EIF_TYPE_INDEX a_type)
{
	const char* l_generator;
#ifdef GE_USE_TYPE_GENERATOR
/* TODO: check that `a_type' is valid. */
	l_generator = GE_type_infos[a_type].generator;
#else
	l_generator = "";
#endif
	return GE_str8(l_generator);
}

/*
 * Full name of `a_type'.
 */
EIF_REFERENCE GE_generating_type_of_encoded_type(EIF_ENCODED_TYPE a_type)
{
	const char* l_name;
#ifdef GE_USE_TYPE_NAME
/* TODO: check that `a_type' is valid. */
	EIF_TYPE l_decoded_type;

	l_decoded_type = GE_decoded_type(a_type);
	l_name = GE_type_infos[l_decoded_type.id].name;
	if (!l_decoded_type.annotations) {
		l_name++;
	}
#else
	l_name = "";
#endif
	return GE_str(l_name);
}

EIF_REFERENCE GE_generating_type_8_of_encoded_type(EIF_ENCODED_TYPE a_type)
{
	const char* l_name;
#ifdef GE_USE_TYPE_NAME
/* TODO: check that `a_type' is valid. */
	EIF_TYPE l_decoded_type;

	l_decoded_type = GE_decoded_type(a_type);
	l_name = GE_type_infos[l_decoded_type.id].name;
	if (!l_decoded_type.annotations) {
		l_name++;
	}
#else
	l_name = "";
#endif
	return GE_str8(l_name);
}

/*
 * Encoded type whose name is `a_name'.
 * -1 if no such type.
 */
EIF_ENCODED_TYPE GE_encoded_type_from_name(EIF_POINTER a_name)
{
#ifdef GE_USE_TYPE_NAME
	int i;
	const char* l_name;

	for (i = 1; i <= GE_type_info_count; i++) {
		l_name = GE_type_infos[i].name;
		if (strcmp((char*)a_name, l_name + 1) == 0) {
			return GE_encoded_type(GE_new_type(i, 0x0));
		} else if (strcmp((char*)a_name, l_name) == 0) {
			return GE_encoded_type(GE_new_type(i, ATTACHED_FLAG));
		}
	}
#endif
	return EIF_NO_TYPE;
}

/*
 * Does `a_type_1' conform to `a_type_2'?
 */
EIF_BOOLEAN GE_encoded_type_conforms_to(EIF_ENCODED_TYPE a_type_1, EIF_ENCODED_TYPE a_type_2)
{
#ifdef GE_USE_ANCESTORS
	GE_type_info l_type_info_1, l_type_info_2;
	GE_ancestor** l_ancestors;
	uint32_t l_ancestor_count, i;
	EIF_TYPE l_decoded_type_1, l_decoded_type_2;
	EIF_TYPE_INDEX l_type_index_1, l_type_index_2, l_ancestor_type_index;
	uint32_t l_flags_1, l_flags_2;

	l_decoded_type_1 = GE_decoded_type(a_type_1);
	l_decoded_type_2 = GE_decoded_type(a_type_2);
	l_type_index_1 = l_decoded_type_1.id;
	l_type_index_2 = l_decoded_type_2.id;
	l_type_info_1 = GE_type_infos[l_type_index_1];
	l_type_info_2 = GE_type_infos[l_type_index_2];
	l_flags_1 = l_type_info_1.flags;
	l_flags_2 = l_type_info_2.flags;
	if (!(l_flags_1 & GE_TYPE_FLAG_EXPANDED || l_decoded_type_1.annotations & ATTACHED_FLAG) && (l_flags_2 & GE_TYPE_FLAG_EXPANDED || l_decoded_type_2.annotations & ATTACHED_FLAG)) {
		return EIF_FALSE;
	} else if (l_flags_1 & GE_TYPE_FLAG_NONE) {
		return EIF_TEST(!(l_flags_2 & GE_TYPE_FLAG_EXPANDED));
	} else if (l_type_index_1 == l_type_index_2) {
		return EIF_TRUE;
	} else if (l_type_index_1 < l_type_index_2) {
		return EIF_FALSE;
	} else {
		l_ancestors = l_type_info_1.ancestors;
		l_ancestor_count = l_type_info_1.ancestor_count;
		for (i = 0; i < l_ancestor_count; i++) {
			l_ancestor_type_index = l_ancestors[i]->type_id;
			if (l_ancestor_type_index == l_type_index_2) {
				return EIF_TRUE;
			} else if (l_ancestor_type_index > l_type_index_2) {
				return EIF_FALSE;
			}
		}
	}
#endif
	return EIF_FALSE;
}

/*
 * Number of generic parameters.
 */
EIF_INTEGER GE_generic_parameter_count_of_type_index(EIF_TYPE_INDEX a_type)
{
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	return (EIF_INTEGER)GE_type_infos[a_type].generic_parameter_count;
#else
	return (EIF_INTEGER)0;
#endif
}

/*
 * Type of `i'-th generic parameter of `a_type'.
 */
EIF_INTEGER GE_generic_parameter_of_type_index(EIF_TYPE_INDEX a_type, EIF_INTEGER i)
{
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
/* TODO: check that `a_type' and `i' are valid. */
	return (EIF_INTEGER)GE_type_infos[a_type].generic_parameters[i - 1];
#else
	return (EIF_INTEGER)0;
#endif
}

/*
 * Number of fields of an object of dynamic type `a_type'.
 */
EIF_INTEGER GE_field_count_of_type_index(EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_OFFSET)
/* TODO: check that `a_type' is valid. */
	return (EIF_INTEGER)GE_type_infos[a_type].attribute_count;
#else
	return (EIF_INTEGER)0;
#endif
}

/*
 * Physical offset of the `i'-th field for an object of dynamic type `a_type'.
 */
EIF_INTEGER GE_field_offset_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_OFFSET)
/* TODO: check that `a_type' and `i' are valid. */
	return (EIF_INTEGER)GE_type_infos[a_type].attributes[i - 1]->offset;
#else
	return (EIF_INTEGER)0;
#endif
}

/*
 * Name of the `i'-th field for an object of dynamic type `a_type'.
 */
EIF_POINTER GE_field_name_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_NAME)
/* TODO: check that `a_type' and `i' are valid. */
	return (EIF_POINTER)GE_type_infos[a_type].attributes[i - 1]->name;
#else
	return (EIF_POINTER)0;
#endif
}

/*
 * Static type of the `i'-th field for an object of dynamic type `a_type'.
 */
EIF_INTEGER GE_field_static_type_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_TYPE_ID)
/* TODO: check that `a_type' and `i' are valid. */
	return (EIF_INTEGER)GE_type_infos[a_type].attributes[i - 1]->type_id;
#else
	return (EIF_INTEGER)0;
#endif
}

/*
 * Kind of type of the `i'-th field for an object of dynamic type `a_type'.
 */
EIF_INTEGER GE_field_type_kind_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_TYPE_ID)
	uint32_t l_flags = GE_type_infos[GE_decoded_type(GE_type_infos[a_type].attributes[i - 1]->type_id).id].flags;
	if (l_flags & GE_TYPE_FLAG_BASIC_MASK) {
		switch (l_flags & GE_TYPE_FLAG_BASIC_MASK) {
		case GE_TYPE_FLAG_BOOLEAN:
			return (EIF_INTEGER)GE_TYPE_KIND_BOOLEAN;
		case GE_TYPE_FLAG_CHARACTER_8:
			return (EIF_INTEGER)GE_TYPE_KIND_CHARACTER_8;
		case GE_TYPE_FLAG_CHARACTER_32:
			return (EIF_INTEGER)GE_TYPE_KIND_CHARACTER_32;
		case GE_TYPE_FLAG_INTEGER_8:
			return (EIF_INTEGER)GE_TYPE_KIND_INTEGER_8;
		case GE_TYPE_FLAG_INTEGER_16:
			return (EIF_INTEGER)GE_TYPE_KIND_INTEGER_16;
		case GE_TYPE_FLAG_INTEGER_32:
			return (EIF_INTEGER)GE_TYPE_KIND_INTEGER_32;
		case GE_TYPE_FLAG_INTEGER_64:
			return (EIF_INTEGER)GE_TYPE_KIND_INTEGER_64;
		case GE_TYPE_FLAG_NATURAL_8:
			return (EIF_INTEGER)GE_TYPE_KIND_NATURAL_8;
		case GE_TYPE_FLAG_NATURAL_16:
			return (EIF_INTEGER)GE_TYPE_KIND_NATURAL_16;
		case GE_TYPE_FLAG_NATURAL_32:
			return (EIF_INTEGER)GE_TYPE_KIND_NATURAL_32;
		case GE_TYPE_FLAG_NATURAL_64:
			return (EIF_INTEGER)GE_TYPE_KIND_NATURAL_64;
		case GE_TYPE_FLAG_POINTER:
			return (EIF_INTEGER)GE_TYPE_KIND_POINTER;
		case GE_TYPE_FLAG_REAL_32:
			return (EIF_INTEGER)GE_TYPE_KIND_REAL_32;
		case GE_TYPE_FLAG_REAL_64:
			return (EIF_INTEGER)GE_TYPE_KIND_REAL_64;
		default:
			return (EIF_INTEGER)GE_TYPE_KIND_INVALID;
		}
	} else if (l_flags & GE_TYPE_FLAG_EXPANDED) {
		return (EIF_INTEGER)GE_TYPE_KIND_EXPANDED;
	} else {
		return (EIF_INTEGER)GE_TYPE_KIND_REFERENCE;
	}
#else
	return (EIF_INTEGER)GE_TYPE_KIND_INVALID;
#endif
}

/*
 * Physical size of `a_object'.
 */
EIF_NATURAL_64 GE_object_size(EIF_POINTER a_object)
{
#ifdef GE_USE_TYPE_OBJECT_SIZE
	EIF_TYPE_INDEX l_type_index = ((EIF_REFERENCE)(a_object))->id;
	uint64_t l_size = GE_type_infos[l_type_index].object_size;
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	if (GE_is_special_type_index(l_type_index)) {
		EIF_TYPE_INDEX l_generic_parameter = GE_decoded_type(GE_type_infos[l_type_index].generic_parameters[0]).id;
		uint32_t l_flags = GE_type_infos[l_generic_parameter].flags;
		EIF_INTEGER l_capacity = ((EIF_SPECIAL*)a_object)->capacity;
		uint64_t l_item_size;

		if (l_flags & GE_TYPE_FLAG_BASIC_MASK) {
			switch (l_flags & GE_TYPE_FLAG_BASIC_MASK) {
			case GE_TYPE_FLAG_BOOLEAN:
				l_item_size = sizeof(EIF_BOOLEAN);
				break;
			case GE_TYPE_FLAG_CHARACTER_8:
				l_item_size = sizeof(EIF_CHARACTER_8);
				break;
			case GE_TYPE_FLAG_CHARACTER_32:
				l_item_size = sizeof(EIF_CHARACTER_32);
				break;
			case GE_TYPE_FLAG_INTEGER_8:
				l_item_size = sizeof(EIF_INTEGER_8);
				break;
			case GE_TYPE_FLAG_INTEGER_16:
				l_item_size = sizeof(EIF_INTEGER_16);
				break;
			case GE_TYPE_FLAG_INTEGER_32:
				l_item_size = sizeof(EIF_INTEGER_32);
				break;
			case GE_TYPE_FLAG_INTEGER_64:
				l_item_size = sizeof(EIF_INTEGER_64);
				break;
			case GE_TYPE_FLAG_NATURAL_8:
				l_item_size = sizeof(EIF_NATURAL_8);
				break;
			case GE_TYPE_FLAG_NATURAL_16:
				l_item_size = sizeof(EIF_NATURAL_16);
				break;
			case GE_TYPE_FLAG_NATURAL_32:
				l_item_size = sizeof(EIF_NATURAL_32);
				break;
			case GE_TYPE_FLAG_NATURAL_64:
				l_item_size = sizeof(EIF_NATURAL_64);
				break;
			case GE_TYPE_FLAG_POINTER:
				l_item_size = sizeof(EIF_POINTER);
				break;
			case GE_TYPE_FLAG_REAL_32:
				l_item_size = sizeof(EIF_REAL_32);
				break;
			case GE_TYPE_FLAG_REAL_64:
				l_item_size = sizeof(EIF_REAL_64);
				break;
			default:
				l_item_size = 0;
			}
		} else if (l_flags & GE_TYPE_FLAG_EXPANDED) {
			l_item_size = GE_type_infos[l_generic_parameter].object_size;
		} else {
			l_item_size = sizeof(EIF_REFERENCE);
		}
		l_size += l_capacity * l_item_size;
	}
#endif
	return (EIF_NATURAL_64)l_size;
#else
	return (EIF_NATURAL_64)0;
#endif
}

/*
 * Is `i'-th field of objects of type `a_type' a user-defined expanded attribute?
 */
EIF_BOOLEAN GE_is_field_expanded_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type)
{
#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_TYPE_ID)
	uint32_t l_flags = GE_type_infos[GE_decoded_type(GE_type_infos[a_type].attributes[i - 1]->type_id).id].flags;
	return EIF_TEST((l_flags & GE_TYPE_FLAG_EXPANDED) && !(l_flags & GE_TYPE_FLAG_BASIC_MASK));
#else
	return EIF_FALSE;
#endif
}

/*
 * Get a lock on `GE_mark_object' and `GE_unmark_object' routines so that
 * 2 threads cannot `GE_mark_object' and `GE_unmark_object' at the same time.
 */
void GE_lock_marking(void)
{
#ifdef GE_USE_THREADS
/* TODO */
#endif
}

/*
 * Release a lock on `GE_mark_object' and `GE_unmark_object', so that another
 * thread can use `GE_mark_object' and `GE_unmark_object'.
 */
void GE_unlock_marking(void)
{
#ifdef GE_USE_THREADS
/* TODO */
#endif
}

/*
 * Is `obj' marked?
 */
EIF_BOOLEAN GE_is_object_marked(EIF_POINTER obj)
{
	return EIF_TEST(((EIF_REFERENCE)obj)->flags & GE_OBJECT_FLAG_MARKED);
}

/*
 * Mark `obj'.
 */
void GE_mark_object(EIF_POINTER obj)
{
	((EIF_REFERENCE)obj)->flags |= GE_OBJECT_FLAG_MARKED;
}

/*
 * Unmark `obj'.
 */
void GE_unmark_object(EIF_POINTER obj)
{
	((EIF_REFERENCE)obj)->flags &= ~GE_OBJECT_FLAG_MARKED;
}

/*
 * New instance of dynamic `a_type'.
 * Note: returned object is not initialized and may
 * hence violate its invariant.
 * `a_type' cannot represent a SPECIAL type, use
 * `GE_new_special_of_reference_instance_of_type_index' instead.
 */
EIF_REFERENCE GE_new_instance_of_type_index(GE_context* a_context, EIF_TYPE_INDEX a_type)
{
	EIF_REFERENCE (*l_new)(GE_context*, EIF_BOOLEAN);

	l_new = (EIF_REFERENCE (*)(GE_context*, EIF_BOOLEAN))GE_type_infos[a_type].new_instance;
	if (l_new) {
		return l_new(a_context, EIF_TRUE);
	} else {
		return EIF_VOID;
	}
}

/*
 * New instance of dynamic `a_type' that represents
 * a SPECIAL with can contain `a_capacity' elements of reference type.
 * To create a SPECIAL of basic type, use class SPECIAL directly.
 */
EIF_REFERENCE GE_new_special_of_reference_instance_of_type_index(GE_context* a_context, EIF_TYPE_INDEX a_type, EIF_INTEGER a_capacity)
{
	EIF_REFERENCE (*l_new)(GE_context*, EIF_INTEGER, EIF_BOOLEAN);

	l_new = (EIF_REFERENCE (*)(GE_context*, EIF_INTEGER, EIF_BOOLEAN))GE_type_infos[a_type].new_instance;
	if (l_new) {
		return l_new(a_context, a_capacity, EIF_TRUE);
	} else {
		return EIF_VOID;
	}
}

/*
 * New instance of TYPE for object of type `a_type'.
 */
EIF_REFERENCE GE_new_type_instance_of_encoded_type(GE_context* a_context, EIF_ENCODED_TYPE a_type)
{
	EIF_TYPE l_decoded_type;
	EIF_TYPE_INDEX l_type_index;
	EIF_TYPE_INDEX l_annotations;
	EIF_REFERENCE l_result;

	l_decoded_type = GE_decoded_type(a_type);
	l_type_index = l_decoded_type.id;
	l_annotations = l_decoded_type.annotations;
	l_result = (EIF_REFERENCE)&(GE_types[l_type_index][l_annotations]);
	if (l_result->id == 0) {
		l_result = EIF_VOID;
		GE_raise(GE_EX_PROG);
	}
	return l_result;
}

/*
 * Check whether the `a_type' is in `a_dynamic_type_set'.
 * `nb' is the number of ids in `a_dynamic_type_set'.
 * `a_dynamic_type_set' is sorted in increasing order.
 * A type-id 0 means Void (aka 'detachable NONE').
 */
EIF_BOOLEAN GE_type_in_dynamic_type_set(EIF_TYPE_INDEX a_type, EIF_TYPE_INDEX a_dynamic_type_set[], int nb)
{
	int i;

	if (nb < 1) {
		return EIF_FALSE;
	}
	if (a_type < a_dynamic_type_set[0]) {
		return EIF_FALSE;
	}
	if (a_type > a_dynamic_type_set[nb-1]) {
		return EIF_FALSE;
	}	
	for (i = 0; i < nb; i++) {
		if (a_type == a_dynamic_type_set[i]) {
			return EIF_TRUE;
		} else if (a_type < a_dynamic_type_set[i]) {
				/* type-ids are sorted in increasing order. */
			return EIF_FALSE;
		}
	}
	return EIF_FALSE;
}

#ifdef GE_USE_ATTRIBUTES
/*
 * Attribute with name `a_name' (in lower-case) in type `a_type`.
 * Null if no such attribute.
 */
GE_attribute* GE_attribute_with_name(EIF_TYPE_INDEX a_type, char* a_name)
{
#ifdef GE_USE_ATTRIBUTE_NAME
	uint32_t i;
	uint32_t l_count;
	GE_type_info* l_type_info;
	GE_attribute** l_attributes;
	GE_attribute* l_attribute;

	if (a_type > 0 && a_type <= GE_type_info_count) {
		l_type_info = &(GE_type_infos[a_type]);
		l_count = l_type_info->attribute_count;
		l_attributes = l_type_info->attributes;
		for (i = 0; i < l_count; i++) {
			l_attribute = l_attributes[i];
			if (strcmp(a_name, l_attribute->name) == 0) {
				return l_attribute;
			}
		}
		fprintf(stderr, "H8\n");
	}
#endif
	return (GE_attribute*)0;
}
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to access garbage collector facilities"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_GC_C
#define GE_GC_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_GC_H
#include "ge_gc.h"
#endif
#ifndef GE_TYPES_H
#include "ge_types.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself not collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
void* GE_unprotected_calloc_atomic_uncollectable(size_t nelem, size_t elsize)
{
	void* new_p;

	new_p = GC_malloc_atomic_uncollectable(nelem * elsize);
	if (new_p) {
		GE_memset(new_p, 0, nelem * elsize);
	}
	return new_p;
}
#endif

/*
 * Allocate more memory for the given pointer.
 * The reallocated pointer keeps the same properties (e.g. atomic or not, collectable or not).
 * The extra allocated memory is zeroed.
 * Do not raise an exception when no-more-memory.
 */
void* GE_unprotected_recalloc(void* p, size_t old_nelem, size_t new_nelem, size_t elsize)
{
	void* new_p;
	new_p = GE_unprotected_realloc(p, new_nelem * elsize);
	if (new_p) {
		GE_memset(((char*)new_p) + (old_nelem * elsize), 0, (new_nelem - old_nelem) * elsize);
	}
	return new_p;
}

#if defined(GE_WINDOWS) && defined(__clang__)
/*
 * Memory setting.
 * Workaround for crashes (illegal instruction signal) when calling 
 * `memset` in Azure Devops pipelines under Windows.
 */
void* GE_memset(void* str, int c, size_t n)
{
	size_t i;
	char volatile* s = (char*)str;

	for (i = 0; i < n; i++) {
		s[i] = (char)c;
	}
	return str;
}
#endif

#ifdef GE_USE_BOEHM_GC
/*
 * Call dispose routine on object `C'.
 */
void GE_boehm_dispose(void* C, void* disp) {
	GE_context* ac = GE_current_context();
	uint32_t volatile in_qualified_call = ac->in_qualified_call;
	ac->in_qualified_call = 0;
	((GE_types[((EIF_REFERENCE)C)->id][0]).dispose)(ac, (EIF_REFERENCE) C);
	ac->in_qualified_call = in_qualified_call;
}

/*
 * Call dispose routine `disp' on once-per-object data `data'.
 */
void GE_boehm_dispose_once_per_object_data(void* data, void* disp) {
	((void (*) (void*)) disp)(data);
}
#endif

/* The C side protects an object. */
EIF_OBJECT eif_protect(EIF_REFERENCE object)
{
#ifdef GE_USE_BOEHM_GC
	EIF_REFERENCE* result = (EIF_REFERENCE*)GC_malloc_uncollectable(sizeof(EIF_REFERENCE));
	*result = object;
	return (EIF_OBJECT)result;
#else
	return (EIF_OBJECT)object;
#endif
}

/* The C side weans adopted object. */
EIF_REFERENCE eif_wean(EIF_OBJECT object)
{
#ifdef GE_USE_BOEHM_GC
	EIF_REFERENCE result = eif_access(object);
	GE_free(object);
	return result;
#else
	return (EIF_REFERENCE)object;
#endif
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class CONSOLE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_CONSOLE_C
#define GE_CONSOLE_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef GE_CONSOLE_H
#include "ge_console.h"
#endif
#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif
#ifdef GE_USE_THREADS
#ifndef GE_THREAD_H
#include "ge_thread.h"
#endif
#endif

#ifdef EIF_WINDOWS
#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef EIF_WINDOWS

static EIF_BOOLEAN GE_console_allocated = EIF_FALSE;
#ifdef GE_USE_THREADS
static EIF_POINTER GE_console_mutex = 0;
#endif

/*
 * Initialize mutex to determine whether a new
 * console needs to be created.
 */
void GE_init_console()
{
#ifdef GE_USE_THREADS
	GE_console_mutex = GE_mutex_create();
#endif
}

/*
 * Create a new DOS console if needed (i.e. in case of a Windows application).
 */
void GE_show_console()
{
#ifdef GE_USE_THREADS
	if (GE_console_mutex) {
		GE_mutex_lock(GE_console_mutex);
#endif
	if (!GE_console_allocated) {
		HANDLE hconin, hconout, hconerr;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		BOOL bLaunched;
		BOOL bSuccess;
		int hCrt;
#ifdef __LCC__
extern FILE * __cdecl _fdopen(int, const char *);
extern int _open_osfhandle(long, int);
#elif !defined EIF_BORLAND
		FILE *hf;
#endif

		bSuccess = AllocConsole();
			/* Get all Std handles and raise an IO exception if we fail getting one. */
		hconout = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hconout == INVALID_HANDLE_VALUE) {
#ifdef GE_USE_THREADS
			GE_mutex_unlock(GE_console_mutex);
#endif
			GE_raise(GE_EX_PROG);
		}
		hconerr = GetStdHandle(STD_ERROR_HANDLE);
		if (hconerr == INVALID_HANDLE_VALUE) {
#ifdef GE_USE_THREADS
			GE_mutex_unlock(GE_console_mutex);
#endif
			GE_raise(GE_EX_PROG);
		}
		hconin = GetStdHandle(STD_INPUT_HANDLE);
		if (hconin == INVALID_HANDLE_VALUE) {
#ifdef GE_USE_THREADS
			GE_mutex_unlock(GE_console_mutex);
#endif
			GE_raise(GE_EX_PROG);
		}
		if (bSuccess) {
				/*
					Console was manually created, we are most likely in
					a Windows application that tries to output something.
					Therefore we need to correctly associated all standard
					handles `stdin', `stdout' and `stderr' to the new created console.
					Note: For Borland, the above trick does not work, one has to
					duplicate the handle, unfortunately the solution does not work
					with Microsoft which explains the ifdef statement.
				*/
#if defined(__LCC__) || defined(EIF_BORLAND)
			hCrt = _open_osfhandle((uintptr_t)hconout, _O_TEXT);
			dup2(hCrt, _fileno(stdout));
			hf = _fdopen (hCrt, "w");
			*stdout = *hf;
			setvbuf(stdout, NULL, _IONBF, 0);
#else
			if (!freopen("CONOUT$", "w", stdout)) {
#ifdef GE_USE_THREADS
				GE_mutex_unlock(GE_console_mutex);
#endif
				GE_raise(GE_EX_PROG);
			}
#endif
#if defined(__LCC__) || defined(EIF_BORLAND)
			hCrt = _open_osfhandle((uintptr_t)hconerr, _O_TEXT);
			dup2(hCrt, _fileno(stderr));
			hf = _fdopen(hCrt, "w");
			*stderr = *hf;
			setvbuf(stderr, NULL, _IONBF, 0);
#else
			/* There is no "CONERR$". Use "CONOUT$ instead. "*/
			if (!freopen("CONOUT$", "w", stderr)) {
#ifdef GE_USE_THREADS
				GE_mutex_unlock(GE_console_mutex);
#endif
				GE_raise(GE_EX_PROG);
			}
#endif
#if defined(__LCC__) || defined(EIF_BORLAND)
			hCrt = _open_osfhandle((uintptr_t)hconin, _O_TEXT | _O_RDONLY);
			dup2(hCrt, _fileno(stdin));
			hf = _fdopen(hCrt, "r");
			*stdin = *hf;
#else
			if (!freopen("CONIN$", "r", stdin)) {
#ifdef GE_USE_THREADS
				GE_mutex_unlock(GE_console_mutex);
#endif
				GE_raise(GE_EX_PROG);
			}
#endif
		}
			/*
				We are computing the cursor position to figure out, if the application
				has been launched from a DOS console or from the Windows Shell.
			*/
/*
		GetConsoleScreenBufferInfo(hconout, &csbi);
		bLaunched = ((csbi.dwCursorPosition.X == 0) && (csbi.dwCursorPosition.Y == 0));
		if ((csbi.dwSize.X <= 0) || (csbi.dwSize.Y <= 0))
			bLaunched = FALSE;

		if (bLaunched == TRUE)
			eif_register_cleanup (eif_console_cleanup);
*/

		GE_console_allocated = EIF_TRUE;
	}
#ifdef GE_USE_THREADS
		GE_mutex_unlock(GE_console_mutex);
	}
#endif
}

#endif

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class ARGUMENTS"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_ARGUMENTS_C
#define GE_ARGUMENTS_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_ARGUMENTS_H
#include "ge_arguments.h"
#endif
#ifndef GE_CONSOLE_H
#include "ge_console.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

int GE_argc;
EIF_NATIVE_CHAR** GE_argv;

	/* Clean up function */
typedef void (* EIF_CLEANUP)(EIF_BOOLEAN);
void eif_register_cleanup(EIF_CLEANUP f)
{
	/* TODO: Needed to compile EiffelNet */
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to handle signals"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_SIGNAL_C
#define GE_SIGNAL_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_SIGNAL_H
#include "ge_signal.h"
#endif
#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif
#ifndef GE_CONSOLE_H
#include "ge_console.h"
#endif

#include <signal.h>

#ifdef GE_USE_THREADS
#ifndef GE_THREAD_H
#include "ge_thread.h"
#endif
#elif !defined(GE_WINDOWS) && defined(GE_USE_BOEHM_GC)
#include <pthread.h>
#endif

#ifndef NSIG
#ifdef GE_WINDOWS
#define GE_NSIG 23
#else
#define GE_NSIG 32
#endif
#else
#ifdef GE_USE_THREADS
#define GE_NSIG	32 /* In MT-mode, it is better not to deal with signals above 32. */
#else
#define	GE_NSIG	NSIG /* GE_NSIG is NSIG in a single threaded runtime. */
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef GE_USE_THREADS

static EIF_MUTEX_TYPE* GE_ignored_signals_mutex = 0; /* Mutex to access `GE_ignored_signals'. */

/* Initialize `GE_ignored_signals_mutex'. */
void GE_init_ignored_signals_mutex()
{
	GE_ignored_signals_mutex = (EIF_MUTEX_TYPE*)GE_mutex_create();
}

#elif defined (GE_WINDOWS)
static DWORD GE_root_thread_id = 0; /* Thread ID of the main thread in non-multithreaded mode. */
#elif defined(GE_USE_BOEHM_GC)
static pthread_t GE_root_thread_id = 0; /* Thread ID of the main thread in non-multithreaded mode. */
#endif

/* Indicates which signals are ignored or not. */
static char GE_ignored_signals[GE_NSIG];

/* Indicates which signals were originally ignored or not. */
static char GE_originally_ignored_signals[GE_NSIG];

/*
 * Code to be executed when the signal `a_sig' is raised.
 */
extern void GE_handle_signal(int a_sig);

/*
 * Code to be executed when the floating point exception signal `a_sig' is raised.
 */
extern void GE_handle_fpe_signal(int a_sig);

/*
 * Code to be executed when the signal `a_sig' is raised.
 */
static void GE_handle_general_signal(int a_sig, int is_fpe)
{
	if (!(GE_main_context && GE_main_context->exception_manager)) {
		GE_show_console();
		fprintf(stderr, "\nSignal caught %d while initializing Eiffel system.\n", a_sig);
		exit(1);
	}
#ifdef GE_USE_THREADS
	GE_context* l_context = GE_unprotected_thread_current_context();
#else
	GE_context* l_context = GE_main_context;
#endif
		/* Check if signal was caught in a non-Eiffel thread. In which case we wimply
		 * print out the signal number except if this is SIGINT or SIGBREAK which are
		 * usually the result of a user action to stop the process. */
#if defined(GE_USE_THREADS) || defined(GE_WINDOWS) || defined(GE_USE_BOEHM_GC)
#ifdef GE_USE_THREADS
	if (!l_context)
#elif defined(GE_WINDOWS)
		/* On Windows for a non-multithreaded program, if we are called from a different
		 * thread than the root one, we clearly cannot continue. */
	if (GE_root_thread_id != GetCurrentThreadId())
#elif defined(GE_USE_BOEHM_GC)
	if (!pthread_equal(GE_root_thread_id, pthread_self()))
#endif
	{
#ifdef SIGBREAK
		if (a_sig != SIGINT && a_sig != SIGBREAK)
#else
		if (a_sig != SIGINT)
#endif
		{
			GE_show_console();
			fprintf(stderr, "\nSignal caught %d while in a non-Eiffel thread.\n", a_sig);
		}
		exit(1);
	}
#endif

	{
		void (*old_handler)(int);

		/* Assume default signal handler is SIG_DFL.
		 * Reset signal handler to call Eiffel's signal handler.
		 */

		if (is_fpe) {
			old_handler = signal(a_sig, GE_handle_fpe_signal);
		} else {
			old_handler = signal(a_sig, GE_handle_signal);
		}

		if (old_handler != SIG_DFL) {
			/* Oops - someone called `signal' to override
			 * Eiffel's handler.  Their handler is still
			 * the one to use, so restore it.
			 */
			signal(a_sig, old_handler);
		}
	}

	if (a_sig >= 1 && a_sig < GE_NSIG) {
		char l_ignored;
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_lock(GE_ignored_signals_mutex);
#endif
		l_ignored = GE_ignored_signals[a_sig];
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		if (l_ignored)	/* If signal is to be ignored */
			return; /* Nothing to be done */
	}

	l_context->signal_number = a_sig;
	if (!l_context->exception_manager) {
		GE_show_console();
		fprintf(stderr, "\nSignal caught %d while initializing Eiffel thread.\n", a_sig);
		exit(1);
	}
	GE_raise_with_message((is_fpe?GE_EX_FLOAT:GE_EX_SIG), GE_signal_name(a_sig));
}

/*
 * Code to be executed when the signal `a_sig' is raised.
 */
void GE_handle_signal(int a_sig)
{
	GE_handle_general_signal(a_sig, 0);
}

/*
 * Code to be executed when the floating point exception signal `a_sig' is raised.
 */
void GE_handle_fpe_signal(int a_sig)
{
	GE_handle_general_signal(a_sig, 1);
}

/* Struct for the description of signals. */
struct GE_signal_description {
	int index;				/* Index for Eiffel/C mapping */
	int number;				/* Signal number */
	char *description;		/* Description */
};

/* Descriptions of defined signals. */
static struct GE_signal_description GE_signal_descriptions[] = {
#ifdef SIGHUP
	{ 1, SIGHUP, "Hangup" },
#endif
#ifdef SIGINT
	{ 2, SIGINT, "Interrupt" },
#endif
#ifdef SIGQUIT
	{ 3, SIGQUIT, "Quit" },
#endif
#ifdef SIGILL
	{ 4, SIGILL, "Illegal instruction" },
#endif
#ifdef SIGTRAP
	{ 5, SIGTRAP, "Trace trap" },
#endif
#ifdef SIGABRT
	{ 6, SIGABRT, "Abort" },
#endif
#ifdef SIGIOT
	{ 7, SIGIOT, "IOT instruction" },
#endif
#ifdef SIGEMT
	{ 8, SIGEMT, "EMT instruction" },
#endif
#ifdef SIGFPE
	{ 9, SIGFPE, "Floating point exception" },
#endif
#ifdef SIGKILL
	{ 10, SIGKILL, "Terminator" },
#endif
#ifdef SIGBUS
	{ 11, SIGBUS, "Bus error" },
#endif
#ifdef SIGSEGV
	{ 12, SIGSEGV, "Segmentation violation" },
#endif
#ifdef SIGSYS
	{ 13, SIGSYS, "Bad argument to system call" },
#endif
#ifdef SIGPIPE
	{ 14, SIGPIPE, "Broken pipe" },
#endif
#ifdef SIGALRM
	{ 15, SIGALRM, "Alarm clock" },
#endif
#ifdef SIGTERM
	{ 16, SIGTERM, "Software termination" },
#endif
#ifdef SIGUSR1
	{ 17, SIGUSR1, "User-defined signal #1" },
#endif
#ifdef SIGUSR2
	{ 18, SIGUSR2, "User-defined signal #2" },
#endif
#ifdef SIGCHLD
	{ 19, SIGCHLD, "Death of a child" },
#endif
#ifdef SIGCLD
	{ 20, SIGCLD, "Death of a child" },
#endif
#ifdef SIGIO
	{ 21, SIGIO, "Pending I/O on a descriptor" },
#endif
#ifdef SIGPOLL
	{ 22, SIGPOLL, "Selectable event pending" },
#endif
#ifdef SIGTTIN
	{ 23, SIGTTIN, "Tty input from background" },
#endif
#ifdef SIGTTOU
	{ 24, SIGTTOU, "Tty output from background" },
#endif
#ifdef SIGSTOP
	{ 25, SIGSTOP, "Stop" },
#endif
#ifdef SIGTSTP
	{ 26, SIGTSTP, "Stop from tty" },
#endif
#ifdef SIGXCPU
	{ 27, SIGXCPU, "Cpu time limit exceeded" },
#endif
#ifdef SIGXFSZ
	{ 28, SIGXFSZ, "File size limit exceeded" },
#endif
#ifdef SIGVTALRM
	{ 29, SIGVTALRM, "Virtual time alarm" },
#endif
#ifdef SIGPWR
	{ 30, SIGPWR, "Power-fail" },
#endif
#ifdef SIGPROF
	{ 31, SIGPROF, "Profiling timer alarm" },
#endif
#ifdef SIGWINCH
	{ 32, SIGWINCH, "Window size changed" },
#endif
#ifdef SIGWIND
	{ 33, SIGWIND, "Window change" },
#endif
#ifdef SIGPHONE
	{ 34, SIGPHONE, "Line status change" },
#endif
#ifdef SIGLOST
	{ 35, SIGLOST, "Resource lost" },
#endif
#ifdef SIGURG
	{ 36, SIGURG, "Urgent condition on socket" },
#endif
#ifdef SIGCONT
	{ 37, SIGCONT, "Continue after stop" },
#endif
#ifdef SIGBREAK
	{ 38, SIGBREAK, "Ctrl-Break"},
#endif
	{ 39, 0, "Unknown signal" }
};

/* Description of signal `a_sig'. */
char *GE_signal_name(EIF_INTEGER a_sig)
{
	int i;

	for (i = 0; ; i++) {
		if ((EIF_INTEGER)GE_signal_descriptions[i].number == a_sig || GE_signal_descriptions[i].number == 0) {
			return GE_signal_descriptions[i].description;
		}
	}
}

/* Is signal `a_sig' defined? */
char GE_is_signal_defined(EIF_INTEGER a_sig)
{
	int i;

	if (a_sig < 1 || a_sig >= GE_NSIG) {
		return (char)0;
	}
	for (i = 0; ; i++) {
		if ((EIF_INTEGER)GE_signal_descriptions[i].number == a_sig) {
			return (char)1;
		} else if (GE_signal_descriptions[i].number == 0) {
			return (char)0;
		}
	}
}

/* C signal code for signal of index `idx'. */
EIF_INTEGER GE_signal_map(EIF_INTEGER idx)
{
	int i;

	for (i = 0; ; i++)
		if ((EIF_INTEGER)GE_signal_descriptions[i].index == idx || GE_signal_descriptions[i].number == 0)
			return (EIF_INTEGER)GE_signal_descriptions[i].number;
}

/*
 * Catch signal `a_sig'.
 * Check that the signal is defined.
 */
void GE_catch_signal(EIF_INTEGER a_sig)
{
	if (GE_is_signal_defined(a_sig) == (char)0)
		return;

	/* We may not change the status of SIGPROF because it is possible
	 * that we do (run-time) external profiling. Changing the catch
	 * status of this signal means that profiling stops.
	 */

#ifdef SIGPROF
	if (a_sig == SIGPROF)
		return;
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_lock(GE_ignored_signals_mutex);
#endif
	GE_ignored_signals[a_sig] = 0;
#ifdef SIGTTIN
	if (a_sig == SIGTTIN) {
		signal(SIGTTIN, SIG_DFL);	/* Ignore background input signal */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTTOU
	if (a_sig == SIGTTOU) {
		signal(SIGTTOU, SIG_DFL);	/* Ignore background output signal */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTSTP
	if (a_sig == SIGTSTP) {
		signal(SIGTSTP, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGCONT
	if (a_sig == SIGCONT) {
		signal(SIGCONT, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTRAP
	if (a_sig == SIGTRAP) {
		signal(SIGTRAP, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGFPE
	if (a_sig == SIGFPE) {
		signal(SIGFPE, GE_handle_fpe_signal);		/* Raise an Eiffel exception when caught */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
}

/* 
 * Ignore signal `a_sig'.
 * Check that the signal is defined.
 */
void GE_ignore_signal(EIF_INTEGER a_sig)
{
	if (GE_is_signal_defined(a_sig) == (char)0)
		return;

	/* We may not change the status of SIGPROF because it is possible
	 * that we do (run-time) external profiling. Changing the catch
	 * status of this signal means that profiling stops.
	 */

#ifdef SIGPROF
	if (a_sig == SIGPROF)
		return;
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_lock(GE_ignored_signals_mutex);
#endif
	GE_ignored_signals[a_sig] = 1;
#ifdef SIGTTIN
	if (a_sig == SIGTTIN) {
		signal(SIGTTIN, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTTOU
	if (a_sig == SIGTTOU) {
		signal(SIGTTOU, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTSTP
	if (a_sig == SIGTSTP) {
		signal(SIGTSTP, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGCONT
	if (a_sig == SIGCONT) {
		signal(SIGCONT, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTRAP
	if (a_sig == SIGTRAP) {
		signal(SIGTRAP, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGFPE
	if (a_sig == SIGFPE) {
		signal(SIGFPE, SIG_IGN);
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
}

/*
 * Is signal of number `a_sig' caught?
 * Check that the signal is defined.
 */
char GE_is_signal_caught(EIF_INTEGER a_sig)
{
	char l_ignored;

	if (GE_is_signal_defined(a_sig) == (char)0)
		return (char)0;
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_lock(GE_ignored_signals_mutex);
#endif
	l_ignored = GE_ignored_signals[a_sig];
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
	return (char)((l_ignored == (char)1)? 0: 1);
}

/* Reset all the signals to their default handling. */
void GE_reset_all_signals(void)
{
	int l_sig;
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_lock(GE_ignored_signals_mutex);
#endif
	for (l_sig = 1; l_sig < GE_NSIG; l_sig++)
#ifdef SIGPROF
		if (l_sig != SIGPROF)
#endif
			GE_ignored_signals[l_sig] = GE_originally_ignored_signals[l_sig];
	
#ifdef SIGTTIN
	signal(SIGTTIN, SIG_IGN); /* Ignore background input signal */
#endif
#ifdef SIGTTOU
	signal(SIGTTOU, SIG_IGN); /* Ignore background output signal */
#endif
#ifdef SIGTSTP
	signal(SIGTSTP, SIG_DFL); /* Restore default behaviour */
#endif
#ifdef SIGCONT
	signal(SIGCONT, SIG_DFL); /* Restore default behaviour */
#endif
#ifdef SIGTRAP
	signal(SIGTRAP, SIG_DFL);	/* Restore default behaviour */
#endif
#ifdef SIGFPE
	signal(SIGFPE, GE_handle_fpe_signal); /* Raise an Eiffel exception when caught */
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
}

/* Reset signal `a_sig' to its default handling. */
void GE_reset_signal_to_default(EIF_INTEGER a_sig)
{

	if (GE_is_signal_defined(a_sig) == (char)0)
		return;

	/* We may not change the status of SIGPROF because it is possible
	 * that we do (run-time) external profiling. Changing the catch
	 * status of this signal means that profiling stops.
	 */

#ifdef SIGPROF
	if (a_sig == SIGPROF)
		return;
#endif

#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_lock(GE_ignored_signals_mutex);
#endif
	GE_ignored_signals[a_sig] = GE_originally_ignored_signals[a_sig];
#ifdef SIGTTIN
	if (a_sig == SIGTTIN) {
		signal(SIGTTIN, SIG_IGN);	/* Ignore background input signal */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTTOU
	if (a_sig == SIGTTOU) {
	 	signal(SIGTTOU, SIG_IGN);	/* Ignore background output signal */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTSTP
	if (a_sig == SIGTSTP) {
		signal(SIGTSTP, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGCONT
	if (a_sig == SIGCONT) {
		signal(SIGCONT, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGTRAP
	if (a_sig == SIGTRAP) {
		signal(SIGTRAP, SIG_DFL);	/* Restore default behaviour */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef SIGFPE
	if (a_sig == SIGFPE) {
		signal(SIGFPE, GE_handle_fpe_signal);	/* Raise an Eiffel exception when caught */
#ifdef GE_USE_THREADS
		if (GE_ignored_signals_mutex)
			GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
		return;
	}
#endif
#ifdef GE_USE_THREADS
	if (GE_ignored_signals_mutex)
		GE_mutex_unlock(GE_ignored_signals_mutex);
#endif
}

/* Number of last signal. */
EIF_INTEGER GE_signal_number()
{
	return (EIF_INTEGER)GE_current_context()->signal_number;
}

/*
 * Set signal handlers.
 * To be called at the beginning of the main thread.
 */
void GE_init_signal()
{
	int l_sig;
	void (*old)(int);	/* Old signal handler */

#ifndef GE_USE_THREADS
#if defined(GE_WINDOWS)
	GE_root_thread_id = GetCurrentThreadId();
#elif defined(GE_USE_BOEHM_GC)
	GE_root_thread_id = pthread_self();
#endif
#endif

	for (l_sig = 1; l_sig < GE_NSIG; l_sig++) {
		old = SIG_IGN;
		/* Default to be ignored before handler installation,
		 * in order to avoid immediate signal handling after 
		 * handler installation, when flags have not been 
		 * correctly set. 
		 */
		GE_ignored_signals[l_sig] = 1; 

		switch (l_sig) {

#ifdef GE_USE_THREADS

			/* In Multi-threaded mode, we do not want to call
			* signal() on some specific signals.
			*/

#if defined(GE_USE_POSIX_THREADS)
			/* So far, used in Linux threads */
			case SIGUSR1:
				break;

			case SIGUSR2:
				break;
#endif

#if defined(SIGPTRESCHED) && defined(GE_USE_POSIX_THREADS) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE==199506L)
			/* So far, used in Posix 1003.1c threads */
			case SIGPTRESCHED:
				break;
#endif

#if defined(SIGPTINTR) && defined(GE_USE_POSIX_THREADS) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE==199506L)
			/* So far, used in Posix 1003.1c */
			case SIGPTINTR:
				break;
#endif

#if defined(SIGRTMIN) && defined(GE_USE_POSIX_THREADS) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE==199309L)
			/* So far, used in Posix 1003.1b */
			case SIGRTMIN:
				break;
#endif

#if defined(SIGRTMAX) && defined(GE_USE_POSIX_THREADS) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE==199309L)
			/* So far, used in Posix 1003.1b */
			case SIGRTMAX:
				break;
#endif

#endif /* GE_USE_THREADS */

#ifdef SIGPROF
			/* When profiling, we must not catch this signal. */
			case SIGPROF:
				break;
#endif /* SIGPROF */

			default:
				if (GE_is_signal_defined(l_sig) == (char)1) {
					old = signal(l_sig, GE_handle_signal);
				}
		}			

		if (old == SIG_IGN) {
			GE_ignored_signals[l_sig] = 1;	/* Signal was ignored by default */
		} else {
			GE_ignored_signals[l_sig] = 0;	/* Signal was not ignored */
		}
	}

	/* Hardwired defaults: ignore SIGCHLD (or SIGCLD), SIGIO, SIGURG, SIGCONT
	 * and SIGWINCH if they are defined. That is to say, the Eiffel run-time
	 * will not deliver these to the process if the user does not explicitely
	 * set a handler for them.
	 */

#ifdef SIGCHLD
	if (SIGCHLD >= 1 && SIGCHLD < GE_NSIG) {
		GE_ignored_signals[SIGCHLD] = 1;	/* Ignore death of a child */
		signal(SIGCHLD, SIG_DFL);			/* Restore the default value */
	}
#endif
#ifdef SIGCLD
	if (SIGCLD >= 1 && SIGCLD < GE_NSIG) {
		GE_ignored_signals[SIGCLD] = 1;		/* Ignore death of a child */
	}
#endif
#ifdef SIGIO
	if (SIGIO >= 1 && SIGIO < GE_NSIG) {
		GE_ignored_signals[SIGIO] = 1;		/* Ignore pending I/O on descriptor */
	}
#endif
#ifdef SIGCONT
	if (SIGCONT >= 1 && SIGCONT < GE_NSIG) {
		GE_ignored_signals[SIGCONT] = 1;	/* Ignore continue after a stop */
	}
#endif
#ifdef SIGURG
	if (SIGURG >= 1 && SIGURG < GE_NSIG) {
		GE_ignored_signals[SIGURG] = 1;		/* Ignore urgent condition on socket */
	}
#endif
#ifdef SIGWINCH
	if (SIGWINCH >= 1 && SIGWINCH < GE_NSIG) {
		GE_ignored_signals[SIGWINCH] = 1;	/* Ignore window size change */
		signal(SIGWINCH, SIG_IGN);
	}
#endif
#ifdef SIGTTIN
	if (SIGTTIN >= 1 && SIGTTIN < GE_NSIG) {
		GE_ignored_signals[SIGTTIN] = 1;	/* Ignore background input signal */
		signal(SIGTTIN, SIG_IGN);
	}
#endif
#ifdef SIGTTOU
	if (SIGTTOU >= 1 && SIGTTOU < GE_NSIG) {
		GE_ignored_signals[SIGTTOU] = 1;	/* Ignore background output signal */
		signal(SIGTTOU, SIG_IGN);
	}
#endif

	/* Do not catch SIGTSTP (stop signal from tty like ^Z under csh or ksh)
	 * otherwise job control will not be allowed. However, SIGSTOP is caught.
	 * Likewise, do not catch SIGCONT (continue signal for stopped process).
	 */

#ifdef SIGTSTP
	if (SIGTSTP >= 1 && SIGTSTP < GE_NSIG) {
		GE_ignored_signals[SIGTSTP] = 0;	/* Do not ignore that signal */
		signal(SIGTSTP, SIG_DFL);			/* Restore default behaviour */
	}
#endif
#ifdef SIGCONT
	if (SIGCONT >= 1 && SIGCONT < GE_NSIG) {
		GE_ignored_signals[SIGCONT] = 0;	/* Do not ignore continue signal */
		signal(SIGCONT, SIG_DFL);			/* Restore default behaviour */
	}
#endif

	/* It would not be wise to catch SIGTRAP: C debuggers may use this signal
	 * to do step-by-step execution and we do not want the Eiffel run-time
	 * to interfere with this particular low-level signal--RAM.
	 */

#ifdef SIGTRAP
	if (SIGTRAP >= 1 && SIGTRAP < GE_NSIG) {
		GE_ignored_signals[SIGTRAP] = 0;	/* Do not ignore Trap signal */
		signal(SIGTRAP, SIG_DFL);			/* Restore default behaviour */
	}
#endif

	/* Special treatment for SIGFPE -- always raise an Eiffel exception when
	 * it is caught (unless exception is explicitely ignored, but that's the
	 * handler's problem).
	 */

#ifdef SIGFPE
	if (SIGFPE >= 1 && SIGFPE < GE_NSIG) {
		GE_ignored_signals[SIGFPE] = 0;			/* Do not ignore a floating point signal */
		signal(SIGFPE, GE_handle_fpe_signal);	/* Raise an Eiffel exception when caught */
	}
#endif

	/* Now save all the defaults in the special original status array, in order
	 * for the run-time to know what to do when a signal is restored to its
	 * "default" state.
	 */

	for (l_sig = 1; l_sig < GE_NSIG; l_sig++) {
		GE_originally_ignored_signals[l_sig] = GE_ignored_signals[l_sig];
	}
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement the program initialization"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_MAIN_C
#define GE_MAIN_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_MAIN_H
#include "ge_main.h"
#endif
#ifndef GE_ARGUMENTS_H
#include "ge_arguments.h"
#endif
#ifndef GE_NATIVE_STRING_H
#include "ge_native_string.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif
#ifndef GE_SIGNAL_H
#include "ge_signal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System name.
 */
char* GE_system_name = NULL;

/*
 * Root class name.
 */
char* GE_root_class_name = NULL;

#ifdef EIF_WINDOWS

/*
 * Used in WEL.
 */
HINSTANCE eif_hInstance;
HINSTANCE eif_hPrevInstance;
LPWSTR eif_lpCmdLine;
int eif_nCmdShow;

/*
 * Break the shell command held in `cmd', putting each shell word
 * in a separate array entry, hence building an argument
 * suitable for the 'main'. Note that `cmd' will be altered
 * and `argvp' will point to some chunks of it.
 */
void GE_get_argcargv(EIF_NATIVE_CHAR* cmd, int* argc, EIF_NATIVE_CHAR*** argvp)
{
	int quoted = 0; /* parsing inside a quoted string? */
	int nbs; /* number of backspaces */
	int i;
	EIF_NATIVE_CHAR *p = NULL, *pe = NULL; /* pointers in `cmd' */
	EIF_NATIVE_CHAR *qb = NULL, *q = NULL; /* pointers in arguments */

	*argc = 0;
	/* Remove leading and trailing white spaces */
	for (p = cmd; *p == L' ' || *p == L'\t'; p++)
		; /* empty */
	for (pe = p + GE_nstrlen(p) - 1; pe >= p && (*pe == L' ' || *pe == L'\t'); pe--)
		; /* empty */
	if (p <= pe) {
		*argc = *argc + 1; /* at least one argument */
		qb = q = malloc((pe - p + 2) * sizeof(EIF_NATIVE_CHAR));
		if (!qb) {
			return;
		}
		do {
			switch(*p) {
				case L' ':
				case L'\t':
					if (quoted) {
						do {
							*q++ = *p++;
						} while(*p == L' ' || *p == L'\t');
					} else {
						do {
							p++;
						} while(*p == L' ' || *p == L'\t');
						*q++ = L'\0';
						*argc = *argc + 1;
					}
					break;
				case L'\"':
					quoted = ! quoted;
					p++;
					break;
				case L'\\':
					for (nbs = 0; *p == L'\\'; nbs++)
						*q++ = *p++;
					if (*p == L'\"') {
						if (nbs % 2) { /* odd number of backslashes */
							q -= (nbs + 1) / 2;
							*q++ = *p++;
						} else { /* even number of backslashes */
							quoted = ! quoted;
							q -= nbs / 2;
							p++;
						}
					}
					break;
				default:
					*q++ = *p++;
			}
		} while (p <= pe);
		*q++ = L'\0';
	}

	if (!argvp) {
		free(qb);
		return;
	}

	*argvp = (EIF_NATIVE_CHAR**)malloc((*argc+1)*sizeof(EIF_NATIVE_CHAR*));
	if (!(*argvp)) {
		free(qb);
		return;
	}

	for (i = 0; i < *argc; i++) {
		(*argvp)[i] = qb;
		qb += GE_nstrlen(qb) + 1;
	}
	(*argvp)[i] = (EIF_NATIVE_CHAR*)0;
}

int main(int dummy_arg1, char** dummy_argv)
{
	int code;
	int argc;
	EIF_NATIVE_CHAR** argv;
	EIF_NATIVE_CHAR* cmd;

	GE_init_signal();
	GE_init_gc();
#ifdef GE_USE_THREADS
	GE_init_ignored_signals_mutex();
#endif
	GE_set_windows_exception_filter();
		/* Variables used in WEL. */
	eif_hInstance = GetModuleHandle(NULL);
	eif_hPrevInstance = NULL;
	eif_lpCmdLine = GetCommandLineW();
	eif_nCmdShow = SW_SHOW;
	cmd = GE_nstrdup(GetCommandLineW());
	GE_get_argcargv(cmd, &argc, &argv);
	code = GE_main(argc, argv);
	free(cmd);
	if (argc > 0) {
		free(argv[0]);
	}
	free(argv);
	return code;
}

/*
 * Main entry point when compiling a Windows application.
 * See:
 *    http://en.wikipedia.org/wiki/WinMain
 *    http://msdn2.microsoft.com/en-us/library/ms633559.aspx
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main(0, NULL);
}

#else

int main(int argc, char** argv)
{
	GE_init_signal();
	GE_init_gc();
#ifdef GE_USE_THREADS
	GE_init_ignored_signals_mutex();
#endif
	return GE_main(argc, argv);
}

#endif

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class EXCEPTION"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_EXCEPTION_C
#define GE_EXCEPTION_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif
#ifndef GE_STRING_H
#include "ge_string.h"
#endif
#ifndef GE_CONSOLE_H
#include "ge_console.h"
#endif
#ifndef GE_MAIN_H
#include "ge_main.h"
#endif
#ifdef GE_USE_THREADS
#ifndef GE_THREAD_H
#include "ge_thread.h"
#endif
#endif

#ifdef EIF_WINDOWS
#ifdef __LCC__
#include <windows.h>
#else
#include <winbase.h>
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pre-defined exception tags. No restriction on size.
 */
static char* GE_exception_tags[] = {
	(char*) 0,							/* Nothing */
	"Feature call on void target.",		/* GE_EX_VOID */
	"No more memory.",					/* GE_EX_MEM */
	"Precondition violated.",			/* GE_EX_PRE */
	"Postcondition violated.",			/* GE_EX_POST */
	"Floating point exception.",		/* GE_EX_FLOAT */
	"Class invariant violated.",		/* GE_EX_CINV */
	"Assertion violated.",				/* GE_EX_CHECK */
	"Routine failure.",					/* GE_EX_FAIL */
	"Unmatched inspect value.",			/* GE_EX_WHEN */
	"Non-decreasing loop variant or negative value reached.",		/* GE_EX_VAR */
	"Loop invariant violated.",			/* GE_EX_LINV */
	"Operating system signal.",			/* GE_EX_SIG */
	"Eiffel run-time panic.",			/* GE_EX_BYE */
	"Exception in rescue clause.",		/* GE_EX_RESC */
	"Out of memory.",					/* GE_EX_OMEM */
	"Resumption attempt failed.",		/* GE_EX_RES */
	"Create on deferred.",				/* GE_EX_CDEF */
	"External event.",					/* GE_EX_EXT */
	"Void assigned to expanded.",		/* GE_EX_VEXP */
	"Exception in signal handler.",		/* GE_EX_HDLR */
	"I/O error.",						/* GE_EX_IO */
	"Operating system error.",			/* GE_EX_SYS */
	"Retrieval error.",					/* GE_EX_RETR */
	"Developer exception.",				/* GE_EX_PROG */
	"Eiffel run-time fatal error.",		/* GE_EX_FATAL */
	"CECIL cannot call melted code",	/* GE_EX_DOL */
	"Runtime I/O error.",				/* GE_EX_ISE_IO */
	"COM error.",						/* GE_EX_COM */
	"Runtime check violated.",			/* GE_EX_RT_CHECK */
	"Old expression evaluation failed.",/* GE_EX_OLD */
	"Serialization failed.",			/* GE_EX_SEL */
	"SCOOP processor dirty."			/* GE_EX_DIRTY */
};

/*
 * Exception tag associated with `a_code'.
 */
char* GE_exception_tag(long a_code)
{
	if (a_code < 0) {
		return "User-defined exception.";
	} else if (a_code < 1 || a_code > GE_EX_NEX) {
		return "Unknown exception.";
	} else {
		return GE_exception_tags[a_code];
	}
}

/*
 * Initialize `a_trace'.
 */
static void GE_init_exception_trace_buffer(GE_exception_trace_buffer* a_trace)
{
	a_trace->count = 0;
	a_trace->capacity = 0;
	a_trace->area = (char*)GE_malloc_atomic_uncollectable(4096);
	a_trace->area[0] = '\0';
	a_trace->capacity = 4096;
}

/*
 * Free memory allocated in `a_trace'.
 */
static void GE_free_exception_trace_buffer(GE_exception_trace_buffer* a_trace)
{
	a_trace->count = 0;
	a_trace->capacity = 0;
	if (a_trace->area) {
		GE_free(a_trace->area);
	}
}

/*
 * Append `a_string' to `a_trace'.
 * Resize area if needed.
 */
void GE_append_to_exception_trace_buffer(GE_exception_trace_buffer* a_trace, char* a_string)
{
	int l_length = strlen(a_string);
	uint32_t l_new_capacity;
	char* l_new_area;

	if (a_trace->area) {
		if ((a_trace->capacity - a_trace->count) <= l_length) {
			l_new_capacity = a_trace->capacity + l_length + 512;
			l_new_area = (char*)GE_realloc(a_trace->area, l_new_capacity);
			if (l_new_area) {
				a_trace->area = l_new_area;
				a_trace->capacity = l_new_capacity;
			}
		}
		if ((a_trace->capacity - a_trace->count) > l_length) {
			strcpy(a_trace->area + a_trace->count, a_string);
			a_trace->count += l_length;
		}
	} else {
		GE_init_exception_trace_buffer(a_trace);
		GE_append_to_exception_trace_buffer(a_trace, a_string);
	}
}

/*
 * Wipe out `a_trace'.
 */
void GE_wipe_out_exception_trace_buffer(GE_exception_trace_buffer* a_trace)
{
	if (a_trace->count > 0) {
		a_trace->count = 0;
		a_trace->area[0] = '\0';
	}
}

/*
 * Print first line of exception which contains `a_class_name', `a_feature_name'
 * and `a_tag_name' to `a_trace'.
 */
static void GE_print_class_feature_tag(GE_exception_trace_buffer* a_trace, const char* a_class_name, const char* a_feature_name, const char* a_tag_name)
{
	char buffer[256];
	int l_class_count, l_feature_count, l_tag_count;

		/* We are trying to provide the best format possible so that we can see all the useful
		 * information about the location and the reason of the crash.
		 * Note that the C format `%width[.precision]s' means that we will display `width'
		 * characters on the screen and only `precision' characters from `s' will be displayed,
		 * meaning that if `precision' is smaller than `width' the text is right aligned.
		 *
		 * Note: because `buffer' has a fixed size of 256, we need to use `precision' to avoid
		 * writting more than `buffer' can hold. And for `sprintf', a null character is appended
		 * after the last character written, which should be taken into account.
		 */
	l_class_count = (int)strlen(a_class_name);
	l_feature_count = (int)strlen(a_feature_name);
	l_tag_count = (int)strlen(a_tag_name);

		/* 1 - precision of 211 = 254 - 43, 43 being number of characters written
		 *      for `a_class_name' and `a_feature_name'. */
		/* 2 - precision of 234 = 254 - 20, 20 being number of characters written
		 *      for `a_class_name'.*/
		/* 3 - precision of 254, 254 being number of characters written
		 *      excluding `\n' and null character appended at the end */
		/* 4 - precision of 251, 231 and 208 being number of characters written
		 *      excluding eclipse from above numbers. */
	if (l_class_count > 19) {
		if (l_class_count > 251) {
			sprintf(buffer, "%.251s...\n", a_class_name);
		} else {
			sprintf(buffer, "%*.254s\n", l_class_count, a_class_name);
		}
		GE_append_to_exception_trace_buffer(a_trace, buffer);
		if (l_feature_count > 22) {
			if (l_feature_count > 231) {
				sprintf(buffer, "%.231s...\n", a_feature_name);
			} else {
				sprintf(buffer, "%*.234s\n", 20 + l_feature_count, a_feature_name);
			}
			GE_append_to_exception_trace_buffer(a_trace, buffer);
			if (l_tag_count > 0) {
				if (l_tag_count > 208) {
					sprintf(buffer, "%.208s...\n", a_tag_name);
				} else {
					sprintf(buffer, "%*.211s\n", 43 + l_tag_count, a_tag_name);
				}
				GE_append_to_exception_trace_buffer(a_trace, buffer);
			}
		} else {
			if (l_tag_count > 208) {
				sprintf(buffer, "%*.22s %.208s...\n", 20 + l_feature_count, a_feature_name, a_tag_name);
			} else {
				sprintf(buffer, "%*.22s %*.211s\n", 20 + l_feature_count, a_feature_name, (43 + l_tag_count) - (20 + l_feature_count + 1), a_tag_name);
			}
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		}
	} else {
		if (l_feature_count > 22) {
			if (l_feature_count > 208) {
				sprintf(buffer, "%-19.19s %.208s...\n", a_class_name, a_feature_name);
			} else {
				sprintf(buffer, "%-19.19s %*.211s\n", a_class_name, l_feature_count, a_feature_name);
			}
			GE_append_to_exception_trace_buffer(a_trace, buffer);
			if (l_tag_count > 0) {
				if (l_tag_count > 208) {
					sprintf(buffer, "%.208s...\n", a_tag_name);
				} else {
					sprintf(buffer, "%*.211s\n", 43 + l_tag_count, a_tag_name);
				}
				GE_append_to_exception_trace_buffer(a_trace, buffer);
			}
		} else {
			if (l_tag_count > 208) {
				sprintf(buffer, "%-19.19s %-22.22s %-29.208s...\n", a_class_name, a_feature_name, a_tag_name);
			} else {
				sprintf(buffer, "%-19.19s %-22.22s %-29.211s\n", a_class_name, a_feature_name, a_tag_name);
			}
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		}
	}
}

/*
 * Print second line of exception which contains `a_object_addr', `a_location',
 * `a_reason' and `a_effect' to `a_trace'.
 */
static void GE_print_object_location_reason_effect(GE_exception_trace_buffer* a_trace, void* a_object_addr, char* a_location, char* a_reason, char* a_effect)
{
	char buffer[256];
	int l_location_count, l_reason_count, l_effect_count;

		/* We are trying to provide the best format possible so that we can see all the useful
		 * information about the location and the reason of the crash.
		 * Note that the C format `%width[.precision]s' means that we will display `width'
		 * characters on the screen and only `precision' characters from `s' will be displayed,
		 * meaning that if `precision' is smaller than `width' the text is right aligned.
		 *
		 * Note: because `buffer' has a fixed size of 256, we need to use `precision' to avoid
		 * writting more than `buffer' can hold.
		 */

	l_location_count = (int)strlen(a_location);
	l_reason_count = (int)strlen(a_reason);
	l_effect_count = (int)strlen(a_effect);

		/* 1 - precision of 211 = 254 - 43, 43 being number of characters written
		 *     for `a_object_addr' and `a_location'.
		 * 2 - precision of 181 = 254 - 73, 73 being number of characters written
		 *     for `a_object_addr', `a_location' and `a_reason'.
		 * 3 - 22, number of characters written for `a_location'
		 * 4 - 29, number of characters written for `a_reason' */

		/* Check this for formatting using `printf':
		 * http://en.wikipedia.org/wiki/Printf#printf_format_placeholders */

		/* Print object address with 16 digits to be ready when pointers
		 * will be on 64 bits on all platform. */
	sprintf(buffer, "<%016" EIF_POINTER_DISPLAY ">  ", (unsigned long)(uintptr_t)a_object_addr);
	GE_append_to_exception_trace_buffer(a_trace, buffer);

	if (l_location_count > 22) {
		sprintf(buffer, "%*.254s\n", l_location_count, a_location);
		GE_append_to_exception_trace_buffer(a_trace, buffer);
		if (l_reason_count > 29) {
			sprintf(buffer, "%*.211s\n", 43 + l_reason_count, a_reason);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
			sprintf(buffer, "%*.181s\n", 73 + l_effect_count, a_effect);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		} else {
			sprintf(buffer, "%*.29s %*.181s\n", 43 + l_reason_count, a_reason, (73 + l_effect_count) - (43 + l_reason_count + 1), a_effect);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		}
	} else {
		if (l_reason_count > 29) {
			sprintf(buffer,"%-22.22s %*.211s\n", a_location, l_reason_count, a_reason);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
			sprintf(buffer, "%*.181s\n", 73 + l_effect_count, a_effect);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		} else {
			sprintf(buffer,"%-22.22s %-29.29s %*.181s\n", a_location, a_reason, l_effect_count, a_effect);
			GE_append_to_exception_trace_buffer(a_trace, buffer);
		}
	}
}

/*
 * Print to `a_trace' the exception trace corresponding to `a_context'.
 */
static void GE_print_exception_trace(GE_context* a_context, long a_code, const char* a_tag, GE_exception_trace_buffer* a_trace)
{
	char buffer[1024];
	GE_call* l_call;
	char* l_tag;
	char l_tag_buf[256];
	void* l_object = NULL;
	char* l_location = "";
	char* l_reason;
	char* l_effect;
	char* l_root_class;
	char* l_root_feature = "root's creation";
	const char* l_class_name;
	const char* l_feature_name;
	unsigned long l_thread_id = 0;
	char* l_thread_name = "";
	unsigned long l_region_id = 0;

#ifdef GE_USE_THREADS
	if (a_context == GE_main_context) {
			/* Main thread. */
		l_thread_name = "Root thread";
	} else {
		l_thread_id = (unsigned long)(uint64_t)a_context->thread->thread_id;
		l_thread_name = "Child thread";
	}
#endif	
#ifdef GE_USE_SCOOP
	l_region_id = (unsigned long)(uint64_t)a_context->region;
	sprintf(buffer, "%s\n", "******************************** SCOOP exception ******************************");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer,"%-10.10s 0x%016" EIF_POINTER_DISPLAY " %-12.12s 0x%" EIF_POINTER_DISPLAY " %s\n", "In region", l_region_id, "(region id)", l_thread_id, "(thread id)");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer, "%s\n", "*******************************************************************************");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
#elif defined(GE_USE_THREADS)
	sprintf(buffer, "%s\n", "******************************** Thread exception *****************************");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer,"%-19.19s %-22.22s 0x%" EIF_POINTER_DISPLAY " %s\n", "In thread", l_thread_name, l_thread_id, "(thread id)");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer, "%s\n", "*******************************************************************************");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
#endif
	sprintf(buffer, "%s\n", "-------------------------------------------------------------------------------");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer, "%-19.19s %-22.22s %-29.29s %-6.6s\n", "Class / Object", "Routine", "Nature of exception", "Effect");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	sprintf(buffer, "%s\n", "-------------------------------------------------------------------------------");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	if (GE_root_class_name) {
		l_root_class = GE_root_class_name;
	} else {
		l_root_class = "ROOT CLASS";
	}
	l_call = a_context->call;
	if (l_call && l_call->caller) {
		l_class_name = l_call->class_name;
		l_feature_name = l_call->feature_name;
#ifdef GE_USE_CURRENT_IN_EXCEPTION_TRACE
		l_object = l_call->object;
#endif
	} else {
		l_class_name = l_root_class;
		l_feature_name = l_root_feature;
	}
	if (a_tag) {
		sprintf(l_tag_buf, "%.254s:", a_tag);
		l_tag = l_tag_buf;
	} else {
		l_tag = "";
	}
	GE_print_class_feature_tag(a_trace, l_class_name, l_feature_name, l_tag);
	l_reason = GE_exception_tag(a_code);
	l_effect = "Fail";
	GE_print_object_location_reason_effect(a_trace, l_object, l_location, l_reason, l_effect);
	sprintf(buffer, "%s\n", "-------------------------------------------------------------------------------");
	GE_append_to_exception_trace_buffer(a_trace, buffer);
	while (l_call) {
		l_tag = "";
		GE_print_class_feature_tag(a_trace, l_call->class_name, l_call->feature_name, l_tag);
#ifdef GE_USE_CURRENT_IN_EXCEPTION_TRACE
		l_object = l_call->object;
#endif
		l_reason = "Routine failure.";
		if (l_call->caller) {
			l_effect = "Fail";
		} else {
			l_effect = "Exit";
			if (strcmp(l_call->feature_name, "separate call") == 0) {
				l_reason = "Dirty region.";
			}
		}
		GE_print_object_location_reason_effect(a_trace, l_object, l_location, l_reason, l_effect);
		sprintf(buffer, "%s\n", "-------------------------------------------------------------------------------");
		GE_append_to_exception_trace_buffer(a_trace, buffer);
		l_call = l_call->caller;
	}
}

/*
 * New execution context.
 */
GE_context* GE_new_context(int is_scoop_processor)
{
	GE_context* l_context;

#ifdef GE_USE_SCOOP
	if (is_scoop_processor) {
		/* Use `GE_calloc_atomic' because we want `l_context->region' to be
		 * collected if it is the only reference left. Other data are kept 
		 * alive thanks to a reference from the SCOOP region. */
		l_context = (GE_context*)GE_calloc_atomic(1, sizeof(GE_context));
	} else
#endif
	{
		/* Use `GE_calloc' because we want all data reachable from `l_context'
		 * to be kept alive while `l_context' is alive. */
		l_context = (GE_context*)GE_calloc(1, sizeof(GE_context));
	}
	l_context->exception_trace_enabled = '\1';
	l_context->storable_discard_pointer_values = '\1';
	l_context->pre_ecma_mapping_status = 1;
	return l_context;
}

/*
 * Execution context of main thread.
 * Should be used from the main thread only.
 */
GE_context* GE_main_context = 0;

/*
 * Execution context of current thread.
 */
GE_context* GE_current_context(void)
{
#ifdef GE_USE_THREADS
	return GE_thread_current_context();
#else
	return GE_main_context;
#endif
}

/*
 * Initialization of exception handling.
 */
void GE_init_exception(GE_context* a_context)
{
	EIF_REFERENCE l_exception_manager;

	GE_init_exception_trace_buffer(&a_context->exception_trace_buffer);
	GE_init_exception_trace_buffer(&a_context->last_exception_trace);
#ifdef GE_USE_SCOOP
	if (!a_context->thread->is_scoop_processor) {
#endif
		l_exception_manager = GE_new_exception_manager(a_context, EIF_TRUE);
		a_context->exception_manager = l_exception_manager;
		GE_init_exception_manager(a_context);
#ifdef GE_USE_SCOOP
	}
#endif
}

/*
 * Free memory allocated in `a_context' for exception handling.
 */
void GE_free_exception(GE_context* a_context)
{
	GE_free_exception_trace_buffer(&(a_context->exception_trace_buffer));
	GE_free_exception_trace_buffer(&(a_context->last_exception_trace));
	a_context->exception_manager = EIF_VOID;
}

/*
 * Pointer to function to create a new exception manager object
 * (of type ISE_EXCEPTION_MANAGER).
 */
EIF_REFERENCE (*GE_new_exception_manager)(GE_context*, EIF_BOOLEAN);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.init_exception_manager.
 */
void (*GE_init_exception_manager)(GE_context*);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.last_exception.
 */
EIF_REFERENCE (*GE_last_exception)(GE_context*);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.once_raise.
 */
void (*GE_once_raise)(GE_context*, EIF_REFERENCE);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.set_exception_data.
 */
void (*GE_set_exception_data)(GE_context*, EIF_INTEGER_32, EIF_BOOLEAN, EIF_INTEGER_32, EIF_INTEGER_32, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_INTEGER_32, EIF_BOOLEAN);

/*
 * Jump to execute the rescue of the last routine with a rescue
 * in the call stack.
 */
void GE_jump_to_last_rescue(GE_context* a_context)
{
	char* l_exception_trace;

	GE_rescue* r = a_context->last_rescue;
	if (r != 0) {
		a_context->last_rescue = r->previous;
		a_context->raising_exception = '\0';
		GE_longjmp(r->jb, 1);
	}
	if (a_context->exception_trace_enabled) {
		GE_show_console();
		if (GE_system_name) {
			fprintf(stderr, "\n%s: system execution failed.\n", GE_system_name);
		} else {
			fprintf(stderr, "\nsystem execution failed.\n");
		}
		l_exception_trace = a_context->last_exception_trace.area;
		if (l_exception_trace) {
			fprintf(stderr, "Following is the set of recorded exceptions:\n\n");
			fprintf(stderr, "%s", l_exception_trace);
		} else {
			fprintf(stderr, "No exception trace found.\n");
		}
	}
	exit(1);
}

/*
 * Call feature EXCEPTION_MANAGER.set_exception_data.
 */
static void GE_call_set_exception_data(GE_context* a_context, long code, int new_obj, int signal_code, int error_code, const char* tag, char* recipient, char* eclass, char* rf_routine, char* rf_class, char* trace, int line_number, int is_invariant_entry)
{
	EIF_REFERENCE l_tag;
	EIF_REFERENCE l_recipient;
	EIF_REFERENCE l_eclass;
	EIF_REFERENCE l_rf_routine;
	EIF_REFERENCE l_rf_class;
	EIF_REFERENCE l_trace;

	if (!a_context->exception_manager) {
		fprintf(stderr, "\nsystem execution failed while handling an exception before the initialing the exception manager.\n");
		exit(1);
	}
	if (tag) {
		l_tag = GE_str(tag);
	} else {
		l_tag = GE_ms("", 0);
	}
	if (recipient) {
		l_recipient = GE_str(recipient);
	} else {
		l_recipient = GE_ms("", 0);
	}
	if (eclass) {
		l_eclass = GE_str(eclass);
	} else {
		l_eclass = GE_ms("", 0);
	}
	if (rf_routine) {
		l_rf_routine = GE_str(rf_routine);
	} else {
		l_rf_routine = GE_ms("", 0);
	}
	if (rf_class) {
		l_rf_class = GE_str(rf_class);
	} else {
		l_rf_class = GE_ms("", 0);
	}
	if (trace && a_context->exception_trace_enabled) {
		l_trace = GE_str(trace);
	} else {
		l_trace = GE_ms("", 0);
	}
	GE_set_exception_data(a_context, (EIF_INTEGER_32) code, EIF_TEST(new_obj), (EIF_INTEGER_32) signal_code, (EIF_INTEGER_32) error_code, l_tag, l_recipient, l_eclass, l_rf_routine, l_rf_class, l_trace, (EIF_INTEGER_32) line_number, EIF_TEST(is_invariant_entry));
}

/*
 * Raise an exception.
 */
static void GE_raise_exception(long code, int new_obj, int signal_code, int error_code, const char* tag, char* recipient, char* eclass, char* rf_routine, char* rf_class, char* trace, int line_number, int is_invariant_entry)
{
	char* l_trace;
	GE_exception_trace_buffer* l_trace_buffer;
	GE_context* l_context;
	const char* l_tag;

	l_context = GE_current_context();
	if (!l_context) {
		GE_show_console();
		if (GE_system_name) {
			fprintf(stderr, "\n%s: system execution failed.\n", GE_system_name);
		} else {
			fprintf(stderr, "\nsystem execution failed.\n");
		}
		if (tag) {
			l_tag = tag;
		} else {
			l_tag = "";
		}
		fprintf(stderr, "%s: %s\n", GE_exception_tag(code), l_tag);
		fprintf(stderr, "Panic: No execution context found.\n");
		exit(1);
	} else if (l_context->raising_exception) {
		GE_show_console();
		if (GE_system_name) {
			fprintf(stderr, "\n%s: system execution failed.\n", GE_system_name);
		} else {
			fprintf(stderr, "\nsystem execution failed.\n");
		}
		if (tag) {
			l_tag = tag;
		} else {
			l_tag = "";
		}
		fprintf(stderr, "%s: %s\n", GE_exception_tag(code), l_tag);
		fprintf(stderr, "Panic: A crash occurred while processing exceptions.\n");
		l_trace = l_context->last_exception_trace.area;
		if (l_trace) {
			fprintf(stderr, "Following is the set of recorded exceptions\n");
			fprintf(stderr, "NB: The raised panic may have induced completely inconsistent information:\n\n");
			fprintf(stderr, "%s", l_trace);
		} else {
			fprintf(stderr, "No exception trace found.\n");
		}
		exit(1);
	} else {
		l_context->raising_exception = '\1';
		l_context->exception_code = code;
		l_context->exception_tag = tag;
		if (code != GE_EX_FAIL) {
			GE_wipe_out_exception_trace_buffer(&l_context->last_exception_trace);
		}
		l_trace = trace;
		if (l_context->exception_trace_enabled && !l_trace) {
			l_trace_buffer = &l_context->exception_trace_buffer;
			GE_wipe_out_exception_trace_buffer(l_trace_buffer);
			GE_print_exception_trace(l_context, code, tag, l_trace_buffer);
			l_trace = l_trace_buffer->area;
		}
		if ((code != GE_EX_FAIL) && l_trace) {
			GE_append_to_exception_trace_buffer(&l_context->last_exception_trace, l_trace);
		}
		GE_call_set_exception_data(l_context, code, new_obj, signal_code, error_code, tag, recipient, eclass, rf_routine, rf_class, l_trace, line_number, is_invariant_entry);
		l_context->raising_exception = '\0';
		l_context->exception_code = 0;
		l_context->exception_tag = (char*)0;
		GE_jump_to_last_rescue(l_context);
	}
}

/*
 * Raise an exception with code `a_code'.
 */
void GE_raise(long a_code)
{
	GE_raise_with_message(a_code, NULL);
}

/*
 * Raise an exception with code `a_code' and message `msg'.
 */
void GE_raise_with_message(long a_code, const char* msg)
{
	GE_raise_exception(a_code, 1, -1, -1, msg, NULL, NULL, NULL, NULL, NULL, -1, 0);
}

/*
 * Raise an exception from EXCEPTION_MANAGER.
 */
void GE_developer_raise(long a_code, EIF_POINTER a_meaning, EIF_POINTER a_message)
{
	GE_raise_exception(a_code, 0, -1, -1, (char*)a_message, NULL, NULL, NULL, NULL, NULL, -1, 0);
}

/*
 * Raise exception which was raised the first time a once routine
 * was executed when executing it again.
 */
void GE_raise_once_exception(GE_context* a_context, EIF_REFERENCE a_exception)
{
	GE_once_raise(a_context, a_exception);
}

/*
 * Raise exception which was raised when an old expression was evaluated.
 */
int GE_raise_old_exception(GE_context* a_context, EIF_REFERENCE a_exception)
{
	GE_raise(GE_EX_OLD);
	return 0;
}

/*
 * Exception, if any, which was last raised in `a_context'.
 */
EIF_REFERENCE GE_last_exception_raised(GE_context* a_context)
{
	return GE_last_exception(a_context);
}

/*
 * Set `in_assertion' to 'not b'.
 * Return the opposite of previous value.
 */
EIF_BOOLEAN GE_check_assert(EIF_BOOLEAN b)
{
	EIF_BOOLEAN l_old_value;
	GE_context* l_context;

	l_context = GE_current_context();
	l_old_value = EIF_TEST(!(l_context->in_assertion));
	l_context->in_assertion = (b?0:1);
	return l_old_value;
}

/*
 * Check whether the type id of `obj' is not in `type_ids'.
 * If it is, then raise a CAT-call exception. Don't do anything if `obj' is Void.
 * `nb' is the number of ids in `type_ids' and is expected to be >0.
 * `type_ids' is sorted in increasing order.
 * Return `obj'.
 */
EIF_REFERENCE GE_check_catcall(EIF_REFERENCE obj, EIF_TYPE_INDEX type_ids[], int nb)
{
	if (obj) {
		int type_id = obj->id;
		if (GE_type_in_dynamic_type_set(type_id, type_ids, nb)) {
			GE_show_console();
			fprintf(stderr, "CAT-call error!\n");
#ifdef EIF_DEBUG
			{
				volatile char c;
				fprintf(stderr, "Press Enter...\n");
				scanf("%c", &c);
			}
#endif
			GE_raise_with_message(GE_EX_PROG, "CAT-call error.");
		}
	}
	return (obj);
}

/*
 * Check whether `obj' is Void.
 * If it is, then raise a call-on-void-target exception.
 * Return `obj'.
 */
EIF_REFERENCE GE_check_void(EIF_REFERENCE obj)
{
	if (!obj) {
		GE_show_console();
		fprintf(stderr, "Call on Void target!\n");
		GE_raise(GE_EX_VOID);
	}
	return (obj);
}

#ifdef GE_DEBUG
/*
 * Check whether `obj' is Void.
 * If it is, then raise a call-on-void-target exception.
 * Include the id `i' in the message displayed in the console
 * to help debugging when `obj' is Void.
 * Return `obj'.
 */
EIF_REFERENCE GE_check_void2(EIF_REFERENCE obj, EIF_INTEGER i)
{
	if (!obj) {
		GE_show_console();
		fprintf(stderr, "Call on Void target! (%d)\n", i);
		GE_raise(GE_EX_VOID);
	}
	return (obj);
}
#endif

/*
 * Check whether `ptr' is a null pointer.
 * If it is, then raise a no-more-memory exception.
 * Return `ptr'.
 */
void* GE_check_null(void* ptr)
{
	if (!ptr) {
		GE_show_console();
		fprintf(stderr, "No more memory!\n");
		GE_raise(GE_EX_MEM);
	}
	return (ptr);
}

#ifdef EIF_WINDOWS
static LONG WINAPI GE_windows_exception_filter(LPEXCEPTION_POINTERS a_exception)
{
		/* In order to be able to catch exceptions that cannot be caught by
		 * just using signals on Windows, we need to set `windows_exception_filter'
		 * as an unhandled exception filter.
		 * See https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-exception_record.
		 */

	switch (a_exception->ExceptionRecord->ExceptionCode) {
		case STATUS_STACK_OVERFLOW:
			GE_raise_with_message(GE_EX_EXT, "Stack overflow");
			break;

		case STATUS_INTEGER_DIVIDE_BY_ZERO:
			GE_raise_with_message(GE_EX_FLOAT, "Integer division by Zero");
			break;

		case STATUS_ACCESS_VIOLATION:
			GE_raise_with_message(GE_EX_EXT, "Segmentation violation");
			break;

		default:
			GE_raise_with_message(GE_EX_EXT, "Unhandled exception");
			break;
	}

		/* Possible return values include:
		 * EXCEPTION_CONTINUE_EXECUTION : Returns to the statement that caused the exception
		 *    and re-executes that statement. (Causes an infinite loop of calling the exception
		 *    handler if the handler does not fix the problem)
		 * EXCEPTION_EXECUTE_HANDLER: Passes the exception to default handler, in our case
		 *    none, since `windows_exception_filter' is the default one now.
		 * EXCEPTION_CONTINUE_SEARCH: Continue to search up the stack for a handle
		 */
	return EXCEPTION_EXECUTE_HANDLER;
}

/*
 * Set default exception handler.
 */
void GE_set_windows_exception_filter(void)
{
	LPTOP_LEVEL_EXCEPTION_FILTER old_exception_handler = NULL;
	old_exception_handler = SetUnhandledExceptionFilter (GE_windows_exception_filter);
}
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement once features"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2017-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_ONCE_C
#define GE_ONCE_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_ONCE_H
#include "ge_once.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif
#ifdef GE_USE_THREADS
#ifndef GE_THREAD_H
#include "ge_thread.h"
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Variable to keep track of the call status
 * and results of once-per-process features.
 */
GE_onces* GE_process_onces;

/*
 * Initialize `GE_process_onces'.
 */
void GE_init_onces(
	uint32_t a_boolean_count,
	uint32_t a_character_8_count,
	uint32_t a_character_32_count,
	uint32_t a_integer_8_count,
	uint32_t a_integer_16_count,
	uint32_t a_integer_32_count,
	uint32_t a_integer_64_count,
	uint32_t a_natural_8_count,
	uint32_t a_natural_16_count,
	uint32_t a_natural_32_count,
	uint32_t a_natural_64_count,
	uint32_t a_pointer_count,
	uint32_t a_real_32_count,
	uint32_t a_real_64_count,
	uint32_t a_reference_count,
	uint32_t a_procedure_count)
{
	GE_process_onces = GE_new_onces(
		a_boolean_count,
		a_character_8_count,
		a_character_32_count,
		a_integer_8_count,
		a_integer_16_count,
		a_integer_32_count,
		a_integer_64_count,
		a_natural_8_count,
		a_natural_16_count,
		a_natural_32_count,
		a_natural_64_count,
		a_pointer_count,
		a_real_32_count,
		a_real_64_count,
		a_reference_count,
		a_procedure_count);
#ifdef GE_USE_THREADS
	GE_process_once_mutexes = GE_new_once_mutexes(
		a_boolean_count,
		a_character_8_count,
		a_character_32_count,
		a_integer_8_count,
		a_integer_16_count,
		a_integer_32_count,
		a_integer_64_count,
		a_natural_8_count,
		a_natural_16_count,
		a_natural_32_count,
		a_natural_64_count,
		a_pointer_count,
		a_real_32_count,
		a_real_64_count,
		a_reference_count,
		a_procedure_count);
#endif
}

/*
 * Create a new 'GE_onces' struct which can deal with the
 * numbers of once features passed as argument.
 */
GE_onces* GE_new_onces(
	uint32_t a_boolean_count,
	uint32_t a_character_8_count,
	uint32_t a_character_32_count,
	uint32_t a_integer_8_count,
	uint32_t a_integer_16_count,
	uint32_t a_integer_32_count,
	uint32_t a_integer_64_count,
	uint32_t a_natural_8_count,
	uint32_t a_natural_16_count,
	uint32_t a_natural_32_count,
	uint32_t a_natural_64_count,
	uint32_t a_pointer_count,
	uint32_t a_real_32_count,
	uint32_t a_real_64_count,
	uint32_t a_reference_count,
	uint32_t a_procedure_count)
{
	GE_onces* l_onces;

	l_onces = (GE_onces*)GE_calloc_uncollectable(1, sizeof(GE_onces));
	if (a_boolean_count > 0) {
		l_onces->boolean_value = (EIF_BOOLEAN*)GE_calloc_atomic(1, a_boolean_count * sizeof(EIF_BOOLEAN));
		l_onces->boolean_exception = (EIF_REFERENCE*)GE_calloc(1, a_boolean_count * sizeof(EIF_REFERENCE));
		l_onces->boolean_status = (unsigned char*)GE_calloc_atomic(1, a_boolean_count * sizeof(unsigned char));
		l_onces->boolean_count = a_boolean_count;
	}
	if (a_character_8_count > 0) {
		l_onces->character_8_value = (EIF_CHARACTER_8*)GE_calloc_atomic(1, a_character_8_count * sizeof(EIF_CHARACTER_8));
		l_onces->character_8_exception = (EIF_REFERENCE*)GE_calloc(1, a_character_8_count * sizeof(EIF_REFERENCE));
		l_onces->character_8_status = (unsigned char*)GE_calloc_atomic(1, a_character_8_count * sizeof(unsigned char));
		l_onces->character_8_count = a_character_8_count;
	}
	if (a_character_32_count > 0) {
		l_onces->character_32_value = (EIF_CHARACTER_32*)GE_calloc_atomic(1, a_character_32_count * sizeof(EIF_CHARACTER_32));
		l_onces->character_32_exception = (EIF_REFERENCE*)GE_calloc(1, a_character_32_count * sizeof(EIF_REFERENCE));
		l_onces->character_32_status = (unsigned char*)GE_calloc_atomic(1, a_character_32_count * sizeof(unsigned char));
		l_onces->character_32_count = a_character_32_count;
	}
	if (a_integer_8_count > 0) {
		l_onces->integer_8_value = (EIF_INTEGER_8*)GE_calloc_atomic(1, a_integer_8_count * sizeof(EIF_INTEGER_8));
		l_onces->integer_8_exception = (EIF_REFERENCE*)GE_calloc(1, a_integer_8_count * sizeof(EIF_REFERENCE));
		l_onces->integer_8_status = (unsigned char*)GE_calloc_atomic(1, a_integer_8_count * sizeof(unsigned char));
		l_onces->integer_8_count = a_integer_8_count;
	}
	if (a_integer_16_count > 0) {
		l_onces->integer_16_value = (EIF_INTEGER_16*)GE_calloc_atomic(1, a_integer_16_count * sizeof(EIF_INTEGER_16));
		l_onces->integer_16_exception = (EIF_REFERENCE*)GE_calloc(1, a_integer_16_count * sizeof(EIF_REFERENCE));
		l_onces->integer_16_status = (unsigned char*)GE_calloc_atomic(1, a_integer_16_count * sizeof(unsigned char));
		l_onces->integer_16_count = a_integer_16_count;
	}
	if (a_integer_32_count > 0) {
		l_onces->integer_32_value = (EIF_INTEGER_32*)GE_calloc_atomic(1, a_integer_32_count * sizeof(EIF_INTEGER_32));
		l_onces->integer_32_exception = (EIF_REFERENCE*)GE_calloc(1, a_integer_32_count * sizeof(EIF_REFERENCE));
		l_onces->integer_32_status = (unsigned char*)GE_calloc_atomic(1, a_integer_32_count * sizeof(unsigned char));
		l_onces->integer_32_count = a_integer_32_count;
	}
	if (a_integer_64_count > 0) {
		l_onces->integer_64_value = (EIF_INTEGER_64*)GE_calloc_atomic(1, a_integer_64_count * sizeof(EIF_INTEGER_64));
		l_onces->integer_64_exception = (EIF_REFERENCE*)GE_calloc(1, a_integer_64_count*  sizeof(EIF_REFERENCE));
		l_onces->integer_64_status = (unsigned char*)GE_calloc_atomic(1, a_integer_64_count * sizeof(unsigned char));
		l_onces->integer_64_count = a_integer_64_count;
	}
	if (a_natural_8_count > 0) {
		l_onces->natural_8_value = (EIF_NATURAL_8*)GE_calloc_atomic(1, a_natural_8_count * sizeof(EIF_NATURAL_8));
		l_onces->natural_8_exception = (EIF_REFERENCE*)GE_calloc(1, a_natural_8_count * sizeof(EIF_REFERENCE));
		l_onces->natural_8_status = (unsigned char*)GE_calloc_atomic(1, a_natural_8_count * sizeof(unsigned char));
		l_onces->natural_8_count = a_natural_8_count;
	}
	if (a_natural_16_count > 0) {
		l_onces->natural_16_value = (EIF_NATURAL_16*)GE_calloc_atomic(1, a_natural_16_count * sizeof(EIF_NATURAL_16));
		l_onces->natural_16_exception = (EIF_REFERENCE*)GE_calloc(1, a_natural_16_count * sizeof(EIF_REFERENCE));
		l_onces->natural_16_status = (unsigned char*)GE_calloc_atomic(1, a_natural_16_count * sizeof(unsigned char));
		l_onces->natural_16_count = a_natural_16_count;
	}
	if (a_natural_32_count > 0) {
		l_onces->natural_32_value = (EIF_NATURAL_32*)GE_calloc_atomic(1, a_natural_32_count * sizeof(EIF_NATURAL_32));
		l_onces->natural_32_exception = (EIF_REFERENCE*)GE_calloc(1, a_natural_32_count * sizeof(EIF_REFERENCE));
		l_onces->natural_32_status = (unsigned char*)GE_calloc_atomic(1, a_natural_32_count *  sizeof(unsigned char));
		l_onces->natural_32_count = a_natural_32_count;
	}
	if (a_natural_64_count > 0) {
		l_onces->natural_64_value = (EIF_NATURAL_64*)GE_calloc_atomic(1, a_natural_64_count * sizeof(EIF_NATURAL_64));
		l_onces->natural_64_exception = (EIF_REFERENCE*)GE_calloc(1, a_natural_64_count * sizeof(EIF_REFERENCE));
		l_onces->natural_64_status = (unsigned char*)GE_calloc_atomic(1, a_natural_64_count * sizeof(unsigned char));
		l_onces->natural_64_count = a_natural_64_count;
	}
	if (a_pointer_count > 0) {
		l_onces->pointer_value = (EIF_POINTER*)GE_calloc_atomic(1, a_pointer_count * sizeof(EIF_POINTER));
		l_onces->pointer_exception = (EIF_REFERENCE*)GE_calloc(1, a_pointer_count * sizeof(EIF_REFERENCE));
		l_onces->pointer_status = (unsigned char*)GE_calloc_atomic(1, a_pointer_count * sizeof(unsigned char));
		l_onces->pointer_count = a_pointer_count;
	}
	if (a_real_32_count > 0) {
		l_onces->real_32_value = (EIF_REAL_32*)GE_calloc_atomic(1, a_real_32_count * sizeof(EIF_REAL_32));
		l_onces->real_32_exception = (EIF_REFERENCE*)GE_calloc(1, a_real_32_count * sizeof(EIF_REFERENCE));
		l_onces->real_32_status = (unsigned char*)GE_calloc_atomic(1, a_real_32_count * sizeof(unsigned char));
		l_onces->real_32_count = a_real_32_count;
	}
	if (a_real_64_count > 0) {
		l_onces->real_64_value = (EIF_REAL_64*)GE_calloc_atomic(1, a_real_64_count * sizeof(EIF_REAL_64));
		l_onces->real_64_exception = (EIF_REFERENCE*)GE_calloc(1, a_real_64_count * sizeof(EIF_REFERENCE));
		l_onces->real_64_status = (unsigned char*)GE_calloc_atomic(1, a_real_64_count * sizeof(unsigned char));
		l_onces->real_64_count = a_real_64_count;
	}
	if (a_reference_count > 0) {
		l_onces->reference_value = (EIF_REFERENCE*)GE_calloc(1, a_reference_count * sizeof(EIF_REFERENCE));
		l_onces->reference_exception = (EIF_REFERENCE*)GE_calloc(1, a_reference_count * sizeof(EIF_REFERENCE));
		l_onces->reference_status = (unsigned char*)GE_calloc_atomic(1, a_reference_count * sizeof(unsigned char));
		l_onces->reference_count = a_reference_count;
	}
	if (a_procedure_count > 0) {
		l_onces->procedure_exception = (EIF_REFERENCE*)GE_calloc(1, a_procedure_count * sizeof(EIF_REFERENCE));
		l_onces->procedure_status = (unsigned char*)GE_calloc_atomic(1, a_procedure_count * sizeof(unsigned char));
		l_onces->procedure_count = a_procedure_count;
	}
	return l_onces;
}

/*
 * Free memory allocated by `a_onces'.
 */
void GE_free_onces(GE_onces* a_onces)
{
	if (a_onces->boolean_value) {
		GE_free(a_onces->boolean_value);
	}
	if (a_onces->boolean_exception) {
		GE_free(a_onces->boolean_exception);
	}
	if (a_onces->boolean_status) {
		GE_free(a_onces->boolean_status);
	}
	if (a_onces->character_8_value) {
		GE_free(a_onces->character_8_value);
	}
	if (a_onces->character_8_exception) {
		GE_free(a_onces->character_8_exception);
	}
	if (a_onces->character_8_status) {
		GE_free(a_onces->character_8_status);
	}
	if (a_onces->character_32_value) {
		GE_free(a_onces->character_32_value);
	}
	if (a_onces->character_32_exception) {
		GE_free(a_onces->character_32_exception);
	}
	if (a_onces->character_32_status) {
		GE_free(a_onces->character_32_status);
	}
	if (a_onces->integer_8_value) {
		GE_free(a_onces->integer_8_value);
	}
	if (a_onces->integer_8_exception) {
		GE_free(a_onces->integer_8_exception);
	}
	if (a_onces->integer_8_status) {
		GE_free(a_onces->integer_8_status);
	}
	if (a_onces->integer_16_value) {
		GE_free(a_onces->integer_16_value);
	}
	if (a_onces->integer_16_exception) {
		GE_free(a_onces->integer_16_exception);
	}
	if (a_onces->integer_16_status) {
		GE_free(a_onces->integer_16_status);
	}
	if (a_onces->integer_32_value) {
		GE_free(a_onces->integer_32_value);
	}
	if (a_onces->integer_32_exception) {
		GE_free(a_onces->integer_32_exception);
	}
	if (a_onces->integer_32_status) {
		GE_free(a_onces->integer_32_status);
	}
	if (a_onces->integer_64_value) {
		GE_free(a_onces->integer_64_value);
	}
	if (a_onces->integer_64_exception) {
		GE_free(a_onces->integer_64_exception);
	}
	if (a_onces->integer_64_status) {
		GE_free(a_onces->integer_64_status);
	}
	if (a_onces->natural_8_value) {
		GE_free(a_onces->natural_8_value);
	}
	if (a_onces->natural_8_exception) {
		GE_free(a_onces->natural_8_exception);
	}
	if (a_onces->natural_8_status) {
		GE_free(a_onces->natural_8_status);
	}
	if (a_onces->natural_16_value) {
		GE_free(a_onces->natural_16_value);
	}
	if (a_onces->natural_16_exception) {
		GE_free(a_onces->natural_16_exception);
	}
	if (a_onces->natural_16_status) {
		GE_free(a_onces->natural_16_status);
	}
	if (a_onces->natural_32_value) {
		GE_free(a_onces->natural_32_value);
	}
	if (a_onces->natural_32_exception) {
		GE_free(a_onces->natural_32_exception);
	}
	if (a_onces->natural_32_status) {
		GE_free(a_onces->natural_32_status);
	}
	if (a_onces->natural_64_value) {
		GE_free(a_onces->natural_64_value);
	}
	if (a_onces->natural_64_exception) {
		GE_free(a_onces->natural_64_exception);
	}
	if (a_onces->natural_64_status) {
		GE_free(a_onces->natural_64_status);
	}
	if (a_onces->pointer_value) {
		GE_free(a_onces->pointer_value);
	}
	if (a_onces->pointer_exception) {
		GE_free(a_onces->pointer_exception);
	}
	if (a_onces->pointer_status) {
		GE_free(a_onces->pointer_status);
	}
	if (a_onces->real_32_value) {
		GE_free(a_onces->real_32_value);
	}
	if (a_onces->real_32_exception) {
		GE_free(a_onces->real_32_exception);
	}
	if (a_onces->real_32_status) {
		GE_free(a_onces->real_32_status);
	}
	if (a_onces->real_64_value) {
		GE_free(a_onces->real_64_value);
	}
	if (a_onces->real_64_exception) {
		GE_free(a_onces->real_64_exception);
	}
	if (a_onces->real_64_status) {
		GE_free(a_onces->real_64_status);
	}
	if (a_onces->reference_value) {
		GE_free(a_onces->reference_value);
	}
	if (a_onces->reference_exception) {
		GE_free(a_onces->reference_exception);
	}
	if (a_onces->reference_status) {
		GE_free(a_onces->reference_status);
	}
	if (a_onces->procedure_exception) {
		GE_free(a_onces->procedure_exception);
	}
	if (a_onces->procedure_status) {
		GE_free(a_onces->procedure_status);
	}
	GE_free(a_onces);
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class IDENTIFIED"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_IDENTIFIED_C
#define GE_IDENTIFIED_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_IDENTIFIED_H
#include "ge_identified.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Weak pointers.
 */

/*
 * Weak pointer structure.
 */
typedef volatile struct {
	EIF_REFERENCE volatile object;
} GE_weak_pointer;

/*
 * Create a new weak pointer to `object'.
 */
static GE_weak_pointer* GE_new_weak_pointer(EIF_REFERENCE object)
{
	GE_weak_pointer* wp;

	if (object == 0) {
		return (GE_weak_pointer*)0;
	} else {
		wp = (GE_weak_pointer*)GE_malloc_atomic(sizeof(GE_weak_pointer));
		wp->object = object;
#ifdef GE_USE_BOEHM_GC
		GC_GENERAL_REGISTER_DISAPPEARING_LINK((void**)(&wp->object), GC_base((void*)object));
#endif
		return wp;
	}
}

/*
 * Direct access to the object held in the weak pointer.
 */
static EIF_REFERENCE GE_weak_pointer_object_without_lock(GE_weak_pointer* wp)
{
	if (wp == 0) {
		return (EIF_REFERENCE)0;
	} else {
		return (wp->object);
	}
}

/*
 * Access to the object held in the weak pointer.
 */
#ifdef GE_USE_BOEHM_GC
static EIF_REFERENCE GE_weak_pointer_object(GE_weak_pointer* wp)
{
	return (EIF_REFERENCE)GC_call_with_alloc_lock((GC_fn_type)GE_weak_pointer_object_without_lock, (void*)wp);
}
#else /* No GC */
#define GE_weak_pointer_object(wp) GE_weak_pointer_object_without_lock(wp)
#endif


/*
 * Identified data structures and functions.
 */

/*
 * Size of inner arrays in `GE_id_objects'.
 */
#define GE_ID_OBJECT_CHUNK_SIZE 512

/*
 * Number of slots to be added to the outer array of
 * `GE_id_objects' when resizing it.
 */
#define GE_ID_OBJECT_CAPACITY_INCREMENT 512

/*
 * Array of arrays of weak pointers. Each inner array has the same size
 * (GE_ID_OBJECT_CHUNK_SIZE). Given an id, the weak pointer associated
 * the object, if any, is at index (id % GE_ID_OBJECT_CHUNK_SIZE) in the
 * inner array located at index (id / GE_ID_OBJECT_CHUNK_SIZE) in the
 * outer array.
 */
static GE_weak_pointer*** GE_id_objects;

/*
 * Capacity of the outer array of `GE_id_objects'.
 */
static EIF_INTEGER_32 GE_id_objects_capacity;

/*
 * Last id associated with an object.
 */
static EIF_INTEGER_32 GE_last_object_id;

/*
 * Initialize data to keep track of object ids.
 */
void GE_init_identified(void)
{
	GE_id_objects = (GE_weak_pointer***)0;
	GE_id_objects_capacity = 0;
	GE_last_object_id = 0;
}

/*
 * Get a new id for `object', assuming it is NOT in the stack.
 */
EIF_INTEGER_32 GE_object_id(EIF_REFERENCE object)
{
	GE_weak_pointer** id_object_chunk;
	EIF_INTEGER_32 i;
	EIF_INTEGER_32 l_old_capacity;

	GE_last_object_id++;
	i = GE_last_object_id / GE_ID_OBJECT_CHUNK_SIZE;
	if (i >= GE_id_objects_capacity) {
		l_old_capacity = GE_id_objects_capacity;
		GE_id_objects_capacity = GE_id_objects_capacity + GE_ID_OBJECT_CAPACITY_INCREMENT;
		if (GE_id_objects == 0) {
			GE_id_objects = GE_calloc_atomic(GE_id_objects_capacity, sizeof(GE_weak_pointer**));
		} else {
			GE_id_objects = GE_recalloc(GE_id_objects, l_old_capacity, GE_id_objects_capacity, sizeof(GE_weak_pointer**));
		}
	}
	id_object_chunk = GE_id_objects[i];
	if (id_object_chunk == 0) {
		id_object_chunk = GE_calloc_uncollectable(GE_ID_OBJECT_CHUNK_SIZE, sizeof(GE_weak_pointer*));
		GE_id_objects[i] = id_object_chunk;
	}
	i = GE_last_object_id % GE_ID_OBJECT_CHUNK_SIZE;
	id_object_chunk[i] = GE_new_weak_pointer(object);
	return GE_last_object_id;
}

/*
 * Return the object associated with `id'.
 */
EIF_REFERENCE GE_id_object(EIF_INTEGER_32 id)
{
	GE_weak_pointer** id_object_chunk;
	GE_weak_pointer* wp;
	EIF_REFERENCE object;
	EIF_INTEGER_32 i;

	i = id / GE_ID_OBJECT_CHUNK_SIZE;
	if (i >= GE_id_objects_capacity) {
		return (EIF_REFERENCE) 0;
	} else {
		id_object_chunk = GE_id_objects[i];
		if (id_object_chunk == 0) {
			return (EIF_REFERENCE)0;
		} else {
			i = id % GE_ID_OBJECT_CHUNK_SIZE;
			wp = id_object_chunk[i];
			if (wp == 0) {
				return (EIF_REFERENCE)0;
			} else {
				object = GE_weak_pointer_object(wp);
				if (object == 0) {
					id_object_chunk[i] = (GE_weak_pointer*)0;
#ifdef GE_USE_BOEHM_GC
					GC_unregister_disappearing_link((void**)(&wp->object));
#endif
					GE_free(wp);
					return (EIF_REFERENCE)0;
				} else {
					return object;
				}
			}
		}
	}
}

/*
 * Remove the object associated with `id' from the stack.
 */
void GE_object_id_free(EIF_INTEGER_32 id)
{
	GE_weak_pointer** id_object_chunk;
	GE_weak_pointer* wp;
	EIF_REFERENCE object;
	EIF_INTEGER_32 i;

	i = id / GE_ID_OBJECT_CHUNK_SIZE;
	if (i < GE_id_objects_capacity) {
		id_object_chunk = GE_id_objects[i];
		if (id_object_chunk != 0) {
			i = id % GE_ID_OBJECT_CHUNK_SIZE;
			wp = id_object_chunk[i];
			if (wp != 0) {
				object = GE_weak_pointer_object(wp);
				if (object != 0) {
#ifdef GE_USE_BOEHM_GC
					GC_unregister_disappearing_link((void**)(&wp->object));
#endif
				}
				id_object_chunk[i] = (GE_weak_pointer*)0;
				GE_free(wp);
			}
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the EiffelCOM library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2010-2025, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_CECIL_C
#define EIF_CECIL_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef EIF_CECIL_H
#include "eif_cecil.h"
#endif
#ifndef GE_CONSOLE_H
#include "ge_console.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

EIF_PROCEDURE eif_procedure(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_procedure' in 'eif_cecil.c' not implemented\n");
	return (EIF_PROCEDURE)0;
}

EIF_INTEGER_FUNCTION eif_integer_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_integer_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_INTEGER_FUNCTION)0;
}

EIF_REFERENCE_FUNCTION eif_reference_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_reference_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_REFERENCE_FUNCTION)0;
}

EIF_POINTER_FUNCTION eif_pointer_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_pointer_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_POINTER_FUNCTION)0;
}

EIF_BOOLEAN_FUNCTION eif_boolean_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_boolean_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_BOOLEAN_FUNCTION)0;
}

EIF_REAL_32_FUNCTION eif_real_32_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_real_32_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_REAL_32_FUNCTION)0;
}

EIF_REAL_64_FUNCTION eif_real_64_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_real_64_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_REAL_64_FUNCTION)0;
}

EIF_CHARACTER_8_FUNCTION eif_character_8_function(char* rout, EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_character_8_function' in 'eif_cecil.c' not implemented\n");
	return (EIF_CHARACTER_8_FUNCTION)0;
}

EIF_OBJECT eif_create(EIF_TYPE_ID cid)
{
	/* TODO */
	GE_show_console();
	fprintf(stderr, "'eif_create' in 'eif_cecil.c' not implemented\n");
	return (EIF_OBJECT)0;
}

EIF_TYPE_ID eif_type_id(char* type_string)
{
	GE_show_console();
	fprintf(stderr, "'eif_type_id' in 'eif_cecil.c' not implemented\n");
	return EIF_NO_TYPE;
}

extern EIF_INTEGER eifaddr_offset(EIF_REFERENCE object, char *name, int * const ret)
{
	GE_show_console();
	fprintf(stderr, "'eifaddr_offset' in 'eif_cecil.c' not implemented\n");
	return 0;
}

EIF_TYPE_ID eiftype(EIF_OBJECT object)
{
		/* Obsolete. Use "eif_type_by_reference" instead.
		 * Return the Type id of the specified object.
		 */
	return (EIF_TYPE_ID)(eif_access(object))->id;
}

EIF_TYPE_ID eif_type_by_reference(EIF_REFERENCE object)
{
		/* Return type id of the direct reference "object" */
	return (EIF_TYPE_ID)object->id;
}

EIF_TYPE_INDEX eif_gen_param_id(EIF_TYPE_INDEX dftype, uint32_t pos)
{
	GE_show_console();
	fprintf(stderr, "'eif_gen_param_id' in 'eif_cecil.c' not implemented\n");
	return 0;
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the EiffelCOM library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2010-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_PLUG_C
#define EIF_PLUG_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef EIF_PLUG_H
#include "eif_plug.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

int nstcall = 0;

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class EXCEPTIONS"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2018, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_EXCEPT_C
#define EIF_EXCEPT_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef EIF_EXCEPT_H
#include "eif_except.h"
#endif
#ifndef GE_STRING_H
#include "ge_string.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Raise an Eiffel exception.
 */
void eraise(const char* name, long code)
{
	GE_raise_with_message(code, name);
}

/*
 * Raise an Eiffel exception of the given code with no associated tag.
 */
void xraise(int code)
{
	GE_raise((long)code);
}

/*
 * Raise an "Operating system error" exception.
 */
void esys(void)
{
	if (errno == 0) {
			/* External event */
		GE_raise(GE_EX_EXT);
	} else {
			/* Operating system error */
		GE_raise(GE_EX_SYS);
	}
}

/*
 * As a special case, an I/O error is raised when a system call which is I/O bound fails.
 */
void eise_io(const char* tag)
{
	GE_raise_with_message(GE_EX_ISE_IO, tag);
}

/*
 * Raise a "No more memory" exception.
 */
void enomem(void) {
	GE_raise(GE_EX_OMEM);
}

/*
 * Raise EiffelCOM exception.
 */
void com_eraise(const char* tag, long num)
{
	GE_raise_with_message(num, tag);
}

/*
 * Terminate execution with exit status `code',
 * without triggering an exception.
 */
void esdie(int code)
{
/* TODO: check that the Boehm GC triggers the 'dispose' routines. */
	exit(code);
}

/*
 * Exception tag associated with `code'.
 * This is a duplication from Eiffel classes, but still used for trace printing and in EiffelCom.
 */
EIF_REFERENCE eename(long code)
{
	return GE_str(GE_exception_tag(code));
}

/*
 * Is exception `ex' defined?
 * Used in EiffelCOM.
 */
char eedefined(long ex)
{
	return (char)((ex > 0 && ex <= GE_EX_NEX)? 1 : 0);
}

/*
 * Enable/diable printing of the exception trace.
 * Per thead information.
 */
void eetrace(char b)
{
	GE_context* context;

	context = GE_current_context();
	context->exception_trace_enabled = b;
}

/*
 * Is current execution during rescue?
 */
EIF_BOOLEAN eif_is_in_rescue(void)
{
	GE_context* context;

	context = GE_current_context();
	return (EIF_TEST(context->in_rescue > 0));
}

#ifdef EIF_WINDOWS
/*
 * Set default exception handler.
 */
void set_windows_exception_filter(void)
{
	GE_set_windows_exception_filter();
}
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
/*
	description:

		"C functions used to implement class COM_FAILURE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2018, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_COM_FAILURE_C
#define GE_COM_FAILURE_C
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_COM_FAILURE_H
#include "ge_com_failure.h"
#endif

#ifdef EIF_WINDOWS
#include <winerror.h>
#include <tchar.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

EIF_INTEGER GE_ccom_hresult(EIF_POINTER an_exception_code)
{
#ifdef EIF_WINDOWS
	char* stopstring = NULL;
	long result = 0, high_bits = 0, low_bits = 0;
	char high_str[7];
	char* exception_code = (char*)(an_exception_code);

	if (exception_code != NULL) {
		strncpy(high_str, exception_code, 6);
		high_str[6] = '\0';

		high_bits = strtol(high_str, &stopstring, 16);
		low_bits = strtol(exception_code + 6, &stopstring, 16);
		result = (high_bits << 16) + low_bits;
	}
	return (EIF_INTEGER)result;
#else
	return 0;
#endif
}

EIF_INTEGER GE_ccom_hresult_code(EIF_INTEGER an_hresult)
{
#ifdef EIF_WINDOWS
	return HRESULT_CODE(an_hresult);
#else
	return 0;
#endif
}

EIF_INTEGER GE_ccom_hresult_facility(EIF_INTEGER an_hresult)
{
#ifdef EIF_WINDOWS
	return HRESULT_FACILITY(an_hresult);
#else
	return 0;
#endif
}

/*
 * Get text from error `a_code'. It is up to the caller to free
 * the returned buffer using `GE_ccom_local_free'.
 */
EIF_POINTER GE_ccom_error_text(EIF_INTEGER a_code)
{
#ifdef EIF_WINDOWS
	volatile LPVOID result;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		a_code,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR)&result,
		0,
		NULL
		);
	return result;
#else
	return 0;
#endif
}

/*
 * Number of characters in `ptr'.
 */
EIF_INTEGER_32 GE_ccom_strlen(EIF_POINTER ptr)
{
#ifdef EIF_WINDOWS
	return (EIF_INTEGER_32)_tcslen((TCHAR*)ptr);
#else
	return 0;
#endif
}

/*
 * Number of bytes occupied by a TCHAR.
 */
EIF_INTEGER_32 GE_ccom_character_size(void)
{
#ifdef EIF_WINDOWS
	return sizeof(TCHAR);
#else
	return 0;
#endif
}

/*
 * Free `a_ptr' using LocalFree.
 */
void GE_ccom_local_free(EIF_POINTER a_ptr)
{
#ifdef EIF_WINDOWS
	LocalFree((HLOCAL)a_ptr);
#endif
}

#ifdef __cplusplus
}
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
