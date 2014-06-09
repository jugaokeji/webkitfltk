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

#include "JSTestSerializedScriptValueInterface.h"

#include "JSMessagePort.h"
#include "MessagePort.h"
#include "ScriptExecutionContext.h"
#include "SerializedScriptValue.h"
#include "TestSerializedScriptValueInterface.h"
#include <runtime/JSArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table for constructor */

static const struct CompactHashIndex JSTestSerializedScriptValueInterfaceConstructorTableIndex[1] = {
    { -1, -1 },
};


static const HashTableValue JSTestSerializedScriptValueInterfaceConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTestSerializedScriptValueInterfaceConstructorTable = { 0, 0, false, JSTestSerializedScriptValueInterfaceConstructorTableValues, 0, JSTestSerializedScriptValueInterfaceConstructorTableIndex };
const ClassInfo JSTestSerializedScriptValueInterfaceConstructor::s_info = { "TestSerializedScriptValueInterfaceConstructor", &Base::s_info, &JSTestSerializedScriptValueInterfaceConstructorTable, 0, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfaceConstructor) };

JSTestSerializedScriptValueInterfaceConstructor::JSTestSerializedScriptValueInterfaceConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestSerializedScriptValueInterfaceConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTestSerializedScriptValueInterfacePrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSTestSerializedScriptValueInterfaceConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestSerializedScriptValueInterfaceConstructor, JSDOMWrapper>(exec, JSTestSerializedScriptValueInterfaceConstructorTable, jsCast<JSTestSerializedScriptValueInterfaceConstructor*>(object), propertyName, slot);
}

/* Hash table for prototype */

static const struct CompactHashIndex JSTestSerializedScriptValueInterfacePrototypeTableIndex[17] = {
    { -1, -1 },
    { -1, -1 },
    { 3, -1 },
    { -1, -1 },
    { -1, -1 },
    { 2, 16 },
    { -1, -1 },
    { 4, -1 },
    { -1, -1 },
    { 0, -1 },
    { -1, -1 },
    { 1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 5, -1 },
};


static const HashTableValue JSTestSerializedScriptValueInterfacePrototypeTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
    { "value", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializedScriptValueInterfaceValue) },
    { "readonlyValue", DontDelete | ReadOnly | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceReadonlyValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
    { "cachedValue", DontDelete | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceCachedValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializedScriptValueInterfaceCachedValue) },
    { "ports", DontDelete | ReadOnly | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfacePorts), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
    { "cachedReadonlyValue", DontDelete | ReadOnly | CustomAccessor, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceCachedReadonlyValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
};

static const HashTable JSTestSerializedScriptValueInterfacePrototypeTable = { 6, 15, true, JSTestSerializedScriptValueInterfacePrototypeTableValues, 0, JSTestSerializedScriptValueInterfacePrototypeTableIndex };
const ClassInfo JSTestSerializedScriptValueInterfacePrototype::s_info = { "TestSerializedScriptValueInterfacePrototype", &Base::s_info, &JSTestSerializedScriptValueInterfacePrototypeTable, 0, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfacePrototype) };

JSObject* JSTestSerializedScriptValueInterfacePrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestSerializedScriptValueInterface>(vm, globalObject);
}

void JSTestSerializedScriptValueInterfacePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestSerializedScriptValueInterfacePrototypeTable, this);
}

const ClassInfo JSTestSerializedScriptValueInterface::s_info = { "TestSerializedScriptValueInterface", &Base::s_info, 0, 0 , CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterface) };

JSTestSerializedScriptValueInterface::JSTestSerializedScriptValueInterface(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestSerializedScriptValueInterface> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl.leakRef())
{
}

JSObject* JSTestSerializedScriptValueInterface::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSTestSerializedScriptValueInterfacePrototype::create(vm, globalObject, JSTestSerializedScriptValueInterfacePrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));
}

void JSTestSerializedScriptValueInterface::destroy(JSC::JSCell* cell)
{
    JSTestSerializedScriptValueInterface* thisObject = static_cast<JSTestSerializedScriptValueInterface*>(cell);
    thisObject->JSTestSerializedScriptValueInterface::~JSTestSerializedScriptValueInterface();
}

JSTestSerializedScriptValueInterface::~JSTestSerializedScriptValueInterface()
{
    releaseImplIfNotNull();
}

EncodedJSValue jsTestSerializedScriptValueInterfaceValue(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestSerializedScriptValueInterface", "value");
        return throwGetterTypeError(*exec, "TestSerializedScriptValueInterface", "value");
    }
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    JSValue result = impl.value() ? impl.value()->deserialize(exec, castedThis->globalObject(), 0) : jsNull();
    return JSValue::encode(result);
}


EncodedJSValue jsTestSerializedScriptValueInterfaceReadonlyValue(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestSerializedScriptValueInterface", "readonlyValue");
        return throwGetterTypeError(*exec, "TestSerializedScriptValueInterface", "readonlyValue");
    }
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    JSValue result = impl.readonlyValue() ? impl.readonlyValue()->deserialize(exec, castedThis->globalObject(), 0) : jsNull();
    return JSValue::encode(result);
}


EncodedJSValue jsTestSerializedScriptValueInterfaceCachedValue(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestSerializedScriptValueInterface", "cachedValue");
        return throwGetterTypeError(*exec, "TestSerializedScriptValueInterface", "cachedValue");
    }
    if (JSValue cachedValue = castedThis->m_cachedValue.get())
        return JSValue::encode(cachedValue);
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    JSValue result = impl.cachedValue() ? impl.cachedValue()->deserialize(exec, castedThis->globalObject(), 0) : jsNull();
    castedThis->m_cachedValue.set(exec->vm(), castedThis, result);
    return JSValue::encode(result);
}


EncodedJSValue jsTestSerializedScriptValueInterfacePorts(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestSerializedScriptValueInterface", "ports");
        return throwGetterTypeError(*exec, "TestSerializedScriptValueInterface", "ports");
    }
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    JSValue result = jsArray(exec, castedThis->globalObject(), impl.ports());
    return JSValue::encode(result);
}


EncodedJSValue jsTestSerializedScriptValueInterfaceCachedReadonlyValue(ExecState* exec, JSObject* slotBase, EncodedJSValue thisValue, PropertyName)
{
    UNUSED_PARAM(exec);
    UNUSED_PARAM(slotBase);
    UNUSED_PARAM(thisValue);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(slotBase))
            return reportDeprecatedGetterError(*exec, "TestSerializedScriptValueInterface", "cachedReadonlyValue");
        return throwGetterTypeError(*exec, "TestSerializedScriptValueInterface", "cachedReadonlyValue");
    }
    if (JSValue cachedValue = castedThis->m_cachedReadonlyValue.get())
        return JSValue::encode(cachedValue);
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    JSValue result = impl.cachedReadonlyValue() ? impl.cachedReadonlyValue()->deserialize(exec, castedThis->globalObject(), 0) : jsNull();
    castedThis->m_cachedReadonlyValue.set(exec->vm(), castedThis, result);
    return JSValue::encode(result);
}


EncodedJSValue jsTestSerializedScriptValueInterfaceConstructor(ExecState* exec, JSObject* baseValue, EncodedJSValue, PropertyName)
{
    JSTestSerializedScriptValueInterfacePrototype* domObject = jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(baseValue);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSTestSerializedScriptValueInterface::getConstructor(exec->vm(), domObject->globalObject()));
}

void setJSTestSerializedScriptValueInterfaceValue(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestSerializedScriptValueInterface", "value");
        else
            throwSetterTypeError(*exec, "TestSerializedScriptValueInterface", "value");
        return;
    }
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    RefPtr<SerializedScriptValue> nativeValue(SerializedScriptValue::create(exec, value, 0, 0));
    if (UNLIKELY(exec->hadException()))
        return;
    impl.setValue(nativeValue);
}


void setJSTestSerializedScriptValueInterfaceCachedValue(ExecState* exec, JSObject* baseObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(baseObject);
    JSTestSerializedScriptValueInterface* castedThis = jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis)) {
        if (jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(JSValue::decode(thisValue)))
            reportDeprecatedSetterError(*exec, "TestSerializedScriptValueInterface", "cachedValue");
        else
            throwSetterTypeError(*exec, "TestSerializedScriptValueInterface", "cachedValue");
        return;
    }
    TestSerializedScriptValueInterface& impl = castedThis->impl();
    RefPtr<SerializedScriptValue> nativeValue(SerializedScriptValue::create(exec, value, 0, 0));
    if (UNLIKELY(exec->hadException()))
        return;
    impl.setCachedValue(nativeValue);
}


JSValue JSTestSerializedScriptValueInterface::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestSerializedScriptValueInterfaceConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

void JSTestSerializedScriptValueInterface::visitChildren(JSCell* cell, SlotVisitor& visitor)
{
    JSTestSerializedScriptValueInterface* thisObject = jsCast<JSTestSerializedScriptValueInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    COMPILE_ASSERT(StructureFlags & OverridesVisitChildren, OverridesVisitChildrenWithoutSettingFlag);
    ASSERT(thisObject->structure()->typeInfo().overridesVisitChildren());
    Base::visitChildren(thisObject, visitor);
    visitor.append(&thisObject->m_cachedValue);
    visitor.append(&thisObject->m_cachedReadonlyValue);
}

bool JSTestSerializedScriptValueInterfaceOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestSerializedScriptValueInterfaceOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSTestSerializedScriptValueInterface* jsTestSerializedScriptValueInterface = jsCast<JSTestSerializedScriptValueInterface*>(handle.slot()->asCell());
    DOMWrapperWorld& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestSerializedScriptValueInterface->impl(), jsTestSerializedScriptValueInterface);
    jsTestSerializedScriptValueInterface->releaseImpl();
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestSerializedScriptValueInterface@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore34TestSerializedScriptValueInterfaceE[]; }
#endif
#endif
JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject* globalObject, TestSerializedScriptValueInterface* impl)
{
    if (!impl)
        return jsNull();
    if (JSValue result = getExistingWrapper<JSTestSerializedScriptValueInterface>(globalObject, impl))
        return result;

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestSerializedScriptValueInterface@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore34TestSerializedScriptValueInterfaceE[2];
#if COMPILER(CLANG)
    // If this fails TestSerializedScriptValueInterface does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    COMPILE_ASSERT(__is_polymorphic(TestSerializedScriptValueInterface), TestSerializedScriptValueInterface_is_not_polymorphic);
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestSerializedScriptValueInterface has subclasses. If TestSerializedScriptValueInterface has subclasses that get passed
    // to toJS() we currently require TestSerializedScriptValueInterface you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createNewWrapper<JSTestSerializedScriptValueInterface>(globalObject, impl);
}

TestSerializedScriptValueInterface* toTestSerializedScriptValueInterface(JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestSerializedScriptValueInterface*>(value))
        return &wrapper->impl();
    return nullptr;
}

}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
