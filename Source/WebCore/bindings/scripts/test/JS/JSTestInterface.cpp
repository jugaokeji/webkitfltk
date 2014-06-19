/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "JSTestInterface.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSTestObj.h"
#include "ScriptExecutionContext.h"
#include "TestInterface.h"
#include "TestObj.h"
#include "TestSupplemental.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

#if ENABLE(Condition11) || ENABLE(Condition12) || ENABLE(Condition22) || ENABLE(Condition23)
#include "JSNode.h"
#include "URL.h"
#include <runtime/JSString.h>
#endif

#if ENABLE(Condition11) || ENABLE(Condition12) || ENABLE(Condition22) || ENABLE(Condition23)
#include "Node.h"
#endif

using namespace JSC;

namespace WebCore {

/* Hash table */

static const struct CompactHashIndex JSTestInterfaceTableIndex[4] = {
    { -1, -1 },
    { 0, -1 },
    { -1, -1 },
    { 1, -1 },
};


static const HashTableValue JSTestInterfaceTableValues[] =
{
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsStr3", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceImplementsStr3), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceImplementsStr3) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalStr3", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSupplementalStr3), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceSupplementalStr3) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
};

static const HashTable JSTestInterfaceTable = { 2, 3, true, JSTestInterfaceTableValues, 0, JSTestInterfaceTableIndex };
/* Hash table for constructor */

static const struct CompactHashIndex JSTestInterfaceConstructorTableIndex[11] = {
    { 8, -1 },
    { 5, -1 },
    { -1, -1 },
    { 0, 9 },
    { 6, 10 },
    { 7, -1 },
    { 2, -1 },
    { 1, 8 },
    { 3, -1 },
    { 4, -1 },
    { 9, -1 },
};


static const HashTableValue JSTestInterfaceConstructorTableValues[] =
{
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "IMPLEMENTSCONSTANT1", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceIMPLEMENTSCONSTANT1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "IMPLEMENTSCONSTANT2", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceIMPLEMENTSCONSTANT2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "SUPPLEMENTALCONSTANT1", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSUPPLEMENTALCONSTANT1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "SUPPLEMENTALCONSTANT2", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSUPPLEMENTALCONSTANT2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsStaticReadOnlyAttr", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceConstructorImplementsStaticReadOnlyAttr), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsStaticAttr", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceConstructorImplementsStaticAttr), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceConstructorImplementsStaticAttr) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalStaticReadOnlyAttr", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceConstructorSupplementalStaticReadOnlyAttr), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalStaticAttr", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceConstructorSupplementalStaticAttr), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceConstructorSupplementalStaticAttr) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsMethod4", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfaceConstructorFunctionImplementsMethod4), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalMethod4", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfaceConstructorFunctionSupplementalMethod4), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
};

static const HashTable JSTestInterfaceConstructorTable = { 10, 7, true, JSTestInterfaceConstructorTableValues, 0, JSTestInterfaceConstructorTableIndex };

#if ENABLE(Condition22) || ENABLE(Condition23)
COMPILE_ASSERT(1 == TestInterface::IMPLEMENTSCONSTANT1, TestInterfaceEnumIMPLEMENTSCONSTANT1IsWrongUseDoNotCheckConstants);
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
COMPILE_ASSERT(2 == TestInterface::CONST_IMPL, TestInterfaceEnumCONST_IMPLIsWrongUseDoNotCheckConstants);
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
COMPILE_ASSERT(1 == TestSupplemental::SUPPLEMENTALCONSTANT1, TestInterfaceEnumSUPPLEMENTALCONSTANT1IsWrongUseDoNotCheckConstants);
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
COMPILE_ASSERT(2 == TestSupplemental::CONST_IMPL, TestInterfaceEnumCONST_IMPLIsWrongUseDoNotCheckConstants);
#endif

EncodedJSValue JSC_HOST_CALL JSTestInterfaceConstructor::constructJSTestInterface(ExecState* exec)
{
    JSTestInterfaceConstructor* castedThis = jsCast<JSTestInterfaceConstructor*>(exec->callee());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createNotEnoughArgumentsError(exec));
    ExceptionCode ec = 0;
    const String& str1(exec->argument(0).isEmpty() ? String() : exec->argument(0).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    const String& str2(exec->argument(1).isEmpty() ? String() : exec->argument(1).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    ScriptExecutionContext* context = castedThis->scriptExecutionContext();
    if (!context)
        return throwConstructorDocumentUnavailableError(*exec, "TestInterface");
    RefPtr<TestInterface> object = TestInterface::create(*context, str1, str2, ec);
    if (ec) {
        setDOMException(exec, ec);
        return JSValue::encode(JSValue());
    }
    return JSValue::encode(asObject(toJS(exec, castedThis->globalObject(), object.get())));
}

const ClassInfo JSTestInterfaceConstructor::s_info = { "TestInterfaceConstructor", &Base::s_info, &JSTestInterfaceConstructorTable, 0, CREATE_METHOD_TABLE(JSTestInterfaceConstructor) };

JSTestInterfaceConstructor::JSTestInterfaceConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestInterfaceConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTestInterfacePrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(1), ReadOnly | DontDelete | DontEnum);
}

bool JSTestInterfaceConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSTestInterfaceConstructor, JSDOMWrapper>(exec, JSTestInterfaceConstructorTable, jsCast<JSTestInterfaceConstructor*>(object), propertyName, slot);
}

#if ENABLE(TEST_INTERFACE)
ConstructType JSTestInterfaceConstructor::getConstructData(JSCell*, ConstructData& constructData)
{
    constructData.native.function = constructJSTestInterface;
    return ConstructTypeHost;
}
#endif // ENABLE(TEST_INTERFACE)

/* Hash table for prototype */

static const struct CompactHashIndex JSTestInterfacePrototypeTableIndex[65] = {
    { -1, -1 },
    { 3, 64 },
    { 14, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 13, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 10, -1 },
    { -1, -1 },
    { 5, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 4, -1 },
    { -1, -1 },
    { 0, -1 },
    { -1, -1 },
    { 7, -1 },
    { -1, -1 },
    { -1, -1 },
    { 15, -1 },
    { 1, -1 },
    { 6, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 11, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 8, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 16, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 2, -1 },
    { 9, -1 },
    { -1, -1 },
    { 12, -1 },
};


static const HashTableValue JSTestInterfacePrototypeTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsStr1", DontDelete | ReadOnly | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceImplementsStr1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsStr2", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceImplementsStr2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceImplementsStr2) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsNode", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceImplementsNode), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceImplementsNode) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalStr1", DontDelete | ReadOnly | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSupplementalStr1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalStr2", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSupplementalStr2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceSupplementalStr2) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalNode", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSupplementalNode), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestInterfaceSupplementalNode) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "IMPLEMENTSCONSTANT1", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceIMPLEMENTSCONSTANT1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "IMPLEMENTSCONSTANT2", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceIMPLEMENTSCONSTANT2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "SUPPLEMENTALCONSTANT1", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSUPPLEMENTALCONSTANT1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "SUPPLEMENTALCONSTANT2", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestInterfaceSUPPLEMENTALCONSTANT2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsMethod1", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionImplementsMethod1), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsMethod2", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionImplementsMethod2), (intptr_t) (2) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
    { "implementsMethod3", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionImplementsMethod3), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalMethod1", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionSupplementalMethod1), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalMethod2", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionSupplementalMethod2), (intptr_t) (2) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    { "supplementalMethod3", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestInterfacePrototypeFunctionSupplementalMethod3), (intptr_t) (0) },
#else
    { 0, 0, NoIntrinsic, 0, 0 },
#endif
};

static const HashTable JSTestInterfacePrototypeTable = { 17, 63, true, JSTestInterfacePrototypeTableValues, 0, JSTestInterfacePrototypeTableIndex };
const ClassInfo JSTestInterfacePrototype::s_info = { "TestInterfacePrototype", &Base::s_info, &JSTestInterfacePrototypeTable, 0, CREATE_METHOD_TABLE(JSTestInterfacePrototype) };

JSObject* JSTestInterfacePrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestInterface>(vm, globalObject);
}

bool JSTestInterfacePrototype::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestInterfacePrototype* thisObject = jsCast<JSTestInterfacePrototype*>(object);
    return getStaticPropertySlot<JSTestInterfacePrototype, JSObject>(exec, JSTestInterfacePrototypeTable, thisObject, propertyName, slot);
}

const ClassInfo JSTestInterface::s_info = { "TestInterface", &Base::s_info, &JSTestInterfaceTable, 0 , CREATE_METHOD_TABLE(JSTestInterface) };

JSTestInterface::JSTestInterface(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestInterface> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl.leakRef())
{
}

JSObject* JSTestInterface::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSTestInterfacePrototype::create(vm, globalObject, JSTestInterfacePrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));
}

void JSTestInterface::destroy(JSC::JSCell* cell)
{
    JSTestInterface* thisObject = static_cast<JSTestInterface*>(cell);
    thisObject->JSTestInterface::~JSTestInterface();
}

JSTestInterface::~JSTestInterface()
{
    releaseImplIfNotNull();
}

bool JSTestInterface::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestInterface* thisObject = jsCast<JSTestInterface*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    return getStaticValueSlot<JSTestInterface, Base>(exec, JSTestInterfaceTable, thisObject, propertyName, slot);
}

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceConstructorImplementsStaticReadOnlyAttr(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSValue result = jsNumber(TestInterface::implementsStaticReadOnlyAttr());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceConstructorImplementsStaticAttr(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSValue result = jsStringWithCache(exec, TestInterface::implementsStaticAttr());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceImplementsStr1(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "implementsStr1");
        return throwGetterTypeError(*exec, "TestInterface", "implementsStr1");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.implementsStr1());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceImplementsStr2(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "implementsStr2");
        return throwGetterTypeError(*exec, "TestInterface", "implementsStr2");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.implementsStr2());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceImplementsStr3(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsCast<JSTestInterface*>(slotBase);
    return JSValue::encode(castedThis->implementsStr3(exec));
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceImplementsNode(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "implementsNode");
        return throwGetterTypeError(*exec, "TestInterface", "implementsNode");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(impl.implementsNode()));
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceConstructorSupplementalStaticReadOnlyAttr(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSValue result = jsNumber(TestSupplemental::supplementalStaticReadOnlyAttr());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceConstructorSupplementalStaticAttr(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSValue result = jsStringWithCache(exec, TestSupplemental::supplementalStaticAttr());
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSupplementalStr1(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "supplementalStr1");
        return throwGetterTypeError(*exec, "TestInterface", "supplementalStr1");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, TestSupplemental::supplementalStr1(&impl));
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSupplementalStr2(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "supplementalStr2");
        return throwGetterTypeError(*exec, "TestInterface", "supplementalStr2");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, TestSupplemental::supplementalStr2(&impl));
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSupplementalStr3(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsCast<JSTestInterface*>(slotBase);
    return JSValue::encode(castedThis->supplementalStr3(exec));
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSupplementalNode(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestInterface", "supplementalNode");
        return throwGetterTypeError(*exec, "TestInterface", "supplementalNode");
    }
    TestInterface& impl = castedThis->impl();
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(TestSupplemental::supplementalNode(&impl)));
    return JSValue::encode(result);
}

#endif

EncodedJSValue jsTestInterfaceConstructor(ExecState* exec, JSObject* baseValue, EncodedJSValue, PropertyName)
{
    JSTestInterfacePrototype* domObject = jsDynamicCast<JSTestInterfacePrototype*>(baseValue);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSTestInterface::getConstructor(exec->vm(), domObject->globalObject()));
}

void JSTestInterface::put(JSCell* cell, ExecState* exec, PropertyName propertyName, JSValue value, PutPropertySlot& slot)
{
    JSTestInterface* thisObject = jsCast<JSTestInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (thisObject->putDelegate(exec, propertyName, value, slot))
        return;
    Base::put(thisObject, exec, propertyName, value, slot);
}

void JSTestInterface::putByIndex(JSCell* cell, ExecState* exec, unsigned index, JSValue value, bool shouldThrow)
{
    JSTestInterface* thisObject = jsCast<JSTestInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    PropertyName propertyName = Identifier::from(exec, index);
    PutPropertySlot slot(thisObject, shouldThrow);
    if (thisObject->putDelegate(exec, propertyName, value, slot))
        return;
    Base::putByIndex(cell, exec, index, value, shouldThrow);
}

#if ENABLE(Condition22) || ENABLE(Condition23)
void setJSTestInterfaceConstructorImplementsStaticAttr(ExecState* exec, JSObject* baseObject, EncodedJSValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    const String& nativeValue(value.isEmpty() ? String() : value.toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return;
    TestInterface::setImplementsStaticAttr(nativeValue);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
void setJSTestInterfaceImplementsStr2(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestInterface", "implementsStr2");
        else
            throwSetterTypeError(*exec, "TestInterface", "implementsStr2");
        return;
    }
    TestInterface& impl = castedThis->impl();
    const String& nativeValue(value.isEmpty() ? String() : value.toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return;
    impl.setImplementsStr2(nativeValue);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
void setJSTestInterfaceImplementsStr3(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsCast<JSTestInterface*>(baseObject);
    UNUSED_PARAM(thisValue);
    UNUSED_PARAM(exec);
    castedThis->setImplementsStr3(exec, value);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
void setJSTestInterfaceImplementsNode(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestInterface", "implementsNode");
        else
            throwSetterTypeError(*exec, "TestInterface", "implementsNode");
        return;
    }
    TestInterface& impl = castedThis->impl();
    Node* nativeValue(toNode(value));
    if (UNLIKELY(exec->hadException()))
        return;
    impl.setImplementsNode(nativeValue);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
void setJSTestInterfaceConstructorSupplementalStaticAttr(ExecState* exec, JSObject* baseObject, EncodedJSValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    const String& nativeValue(value.isEmpty() ? String() : value.toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return;
    TestSupplemental::setSupplementalStaticAttr(nativeValue);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
void setJSTestInterfaceSupplementalStr2(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestInterface", "supplementalStr2");
        else
            throwSetterTypeError(*exec, "TestInterface", "supplementalStr2");
        return;
    }
    TestInterface& impl = castedThis->impl();
    const String& nativeValue(value.isEmpty() ? String() : value.toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return;
    TestSupplemental::setSupplementalStr2(&impl, nativeValue);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
void setJSTestInterfaceSupplementalStr3(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    UNUSED_PARAM(thisValue);
    JSTestInterface* castedThis = jsCast<JSTestInterface*>(baseObject);
    UNUSED_PARAM(thisValue);
    UNUSED_PARAM(exec);
    castedThis->setSupplementalStr3(exec, value);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
void setJSTestInterfaceSupplementalNode(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestInterface", "supplementalNode");
        else
            throwSetterTypeError(*exec, "TestInterface", "supplementalNode");
        return;
    }
    TestInterface& impl = castedThis->impl();
    Node* nativeValue(toNode(value));
    if (UNLIKELY(exec->hadException()))
        return;
    TestSupplemental::setSupplementalNode(&impl, nativeValue);
}

#endif

JSValue JSTestInterface::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestInterfaceConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionImplementsMethod1(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "implementsMethod1");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    TestInterface& impl = castedThis->impl();
    impl.implementsMethod1();
    return JSValue::encode(jsUndefined());
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionImplementsMethod2(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "implementsMethod2");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    TestInterface& impl = castedThis->impl();
    if (exec->argumentCount() < 2)
        return throwVMError(exec, createNotEnoughArgumentsError(exec));
    ExceptionCode ec = 0;
    ScriptExecutionContext* scriptContext = jsCast<JSDOMGlobalObject*>(exec->lexicalGlobalObject())->scriptExecutionContext();
    if (!scriptContext)
        return JSValue::encode(jsUndefined());
    const String& strArg(exec->argument(0).isEmpty() ? String() : exec->argument(0).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    TestObj* objArg(toTestObj(exec->argument(1)));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(impl.implementsMethod2(scriptContext, strArg, objArg, ec)));

    setDOMException(exec, ec);
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionImplementsMethod3(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "implementsMethod3");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    return JSValue::encode(castedThis->implementsMethod3(exec));
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue JSC_HOST_CALL jsTestInterfaceConstructorFunctionImplementsMethod4(ExecState* exec)
{
    TestInterface::implementsMethod4();
    return JSValue::encode(jsUndefined());
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionSupplementalMethod1(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "supplementalMethod1");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    TestInterface& impl = castedThis->impl();
    TestSupplemental::supplementalMethod1(&impl);
    return JSValue::encode(jsUndefined());
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionSupplementalMethod2(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "supplementalMethod2");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    TestInterface& impl = castedThis->impl();
    if (exec->argumentCount() < 2)
        return throwVMError(exec, createNotEnoughArgumentsError(exec));
    ExceptionCode ec = 0;
    ScriptExecutionContext* scriptContext = jsCast<JSDOMGlobalObject*>(exec->lexicalGlobalObject())->scriptExecutionContext();
    if (!scriptContext)
        return JSValue::encode(jsUndefined());
    const String& strArg(exec->argument(0).isEmpty() ? String() : exec->argument(0).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    TestObj* objArg(toTestObj(exec->argument(1)));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(TestSupplemental::supplementalMethod2(&impl, scriptContext, strArg, objArg, ec)));

    setDOMException(exec, ec);
    return JSValue::encode(result);
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue JSC_HOST_CALL jsTestInterfacePrototypeFunctionSupplementalMethod3(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestInterface* castedThis = jsDynamicCast<JSTestInterface*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestInterface", "supplementalMethod3");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestInterface::info());
    return JSValue::encode(castedThis->supplementalMethod3(exec));
}

#endif

#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue JSC_HOST_CALL jsTestInterfaceConstructorFunctionSupplementalMethod4(ExecState* exec)
{
    TestSupplemental::supplementalMethod4();
    return JSValue::encode(jsUndefined());
}

#endif

// Constant getters

#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceIMPLEMENTSCONSTANT1(ExecState*, JSObject*, EncodedJSValue, PropertyName)
{
    return JSValue::encode(jsNumber(1));
}

#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
EncodedJSValue jsTestInterfaceIMPLEMENTSCONSTANT2(ExecState*, JSObject*, EncodedJSValue, PropertyName)
{
    return JSValue::encode(jsNumber(2));
}

#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSUPPLEMENTALCONSTANT1(ExecState*, JSObject*, EncodedJSValue, PropertyName)
{
    return JSValue::encode(jsNumber(1));
}

#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
EncodedJSValue jsTestInterfaceSUPPLEMENTALCONSTANT2(ExecState*, JSObject*, EncodedJSValue, PropertyName)
{
    return JSValue::encode(jsNumber(2));
}

#endif
bool JSTestInterfaceOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    JSTestInterface* jsTestInterface = jsCast<JSTestInterface*>(handle.slot()->asCell());
    if (jsTestInterface->impl().hasPendingActivity())
        return true;
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestInterfaceOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSTestInterface* jsTestInterface = jsCast<JSTestInterface*>(handle.slot()->asCell());
    DOMWrapperWorld& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestInterface->impl(), jsTestInterface);
    jsTestInterface->releaseImpl();
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject* globalObject, TestInterface* impl)
{
    if (!impl)
        return jsNull();
    if (JSValue result = getExistingWrapper<JSTestInterface>(globalObject, impl))
        return result;
#if COMPILER(CLANG)
    // If you hit this failure the interface definition has the ImplementationLacksVTable
    // attribute. You should remove that attribute. If the class has subclasses
    // that may be passed through this toJS() function you should use the SkipVTableValidation
    // attribute to TestInterface.
    COMPILE_ASSERT(!__is_polymorphic(TestInterface), TestInterface_is_polymorphic_but_idl_claims_not_to_be);
#endif
    return createNewWrapper<JSTestInterface>(globalObject, impl);
}

TestInterface* toTestInterface(JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestInterface*>(value))
        return &wrapper->impl();
    return nullptr;
}

}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
