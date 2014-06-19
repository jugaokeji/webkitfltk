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
#include "JSTestCustomNamedGetter.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "TestCustomNamedGetter.h"
#include "wtf/text/AtomicString.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table */

static const struct CompactHashIndex JSTestCustomNamedGetterTableIndex[2] = {
    { -1, -1 },
    { 0, -1 },
};


static const HashTableValue JSTestCustomNamedGetterTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCustomNamedGetterConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
};

static const HashTable JSTestCustomNamedGetterTable = { 1, 1, true, JSTestCustomNamedGetterTableValues, 0, JSTestCustomNamedGetterTableIndex };
/* Hash table for constructor */

static const struct CompactHashIndex JSTestCustomNamedGetterConstructorTableIndex[1] = {
    { -1, -1 },
};


static const HashTableValue JSTestCustomNamedGetterConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTestCustomNamedGetterConstructorTable = { 0, 0, false, JSTestCustomNamedGetterConstructorTableValues, 0, JSTestCustomNamedGetterConstructorTableIndex };
const ClassInfo JSTestCustomNamedGetterConstructor::s_info = { "TestCustomNamedGetterConstructor", &Base::s_info, &JSTestCustomNamedGetterConstructorTable, 0, CREATE_METHOD_TABLE(JSTestCustomNamedGetterConstructor) };

JSTestCustomNamedGetterConstructor::JSTestCustomNamedGetterConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestCustomNamedGetterConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTestCustomNamedGetterPrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSTestCustomNamedGetterConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestCustomNamedGetterConstructor, JSDOMWrapper>(exec, JSTestCustomNamedGetterConstructorTable, jsCast<JSTestCustomNamedGetterConstructor*>(object), propertyName, slot);
}

/* Hash table for prototype */

static const struct CompactHashIndex JSTestCustomNamedGetterPrototypeTableIndex[2] = {
    { -1, -1 },
    { 0, -1 },
};


static const HashTableValue JSTestCustomNamedGetterPrototypeTableValues[] =
{
    { "anotherFunction", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsTestCustomNamedGetterPrototypeFunctionAnotherFunction), (intptr_t) (1) },
};

static const HashTable JSTestCustomNamedGetterPrototypeTable = { 1, 1, false, JSTestCustomNamedGetterPrototypeTableValues, 0, JSTestCustomNamedGetterPrototypeTableIndex };
const ClassInfo JSTestCustomNamedGetterPrototype::s_info = { "TestCustomNamedGetterPrototype", &Base::s_info, &JSTestCustomNamedGetterPrototypeTable, 0, CREATE_METHOD_TABLE(JSTestCustomNamedGetterPrototype) };

JSObject* JSTestCustomNamedGetterPrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestCustomNamedGetter>(vm, globalObject);
}

bool JSTestCustomNamedGetterPrototype::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestCustomNamedGetterPrototype* thisObject = jsCast<JSTestCustomNamedGetterPrototype*>(object);
    return getStaticFunctionSlot<JSObject>(exec, JSTestCustomNamedGetterPrototypeTable, thisObject, propertyName, slot);
}

const ClassInfo JSTestCustomNamedGetter::s_info = { "TestCustomNamedGetter", &Base::s_info, &JSTestCustomNamedGetterTable, 0 , CREATE_METHOD_TABLE(JSTestCustomNamedGetter) };

JSTestCustomNamedGetter::JSTestCustomNamedGetter(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestCustomNamedGetter> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl.leakRef())
{
}

JSObject* JSTestCustomNamedGetter::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSTestCustomNamedGetterPrototype::create(vm, globalObject, JSTestCustomNamedGetterPrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));
}

void JSTestCustomNamedGetter::destroy(JSC::JSCell* cell)
{
    JSTestCustomNamedGetter* thisObject = static_cast<JSTestCustomNamedGetter*>(cell);
    thisObject->JSTestCustomNamedGetter::~JSTestCustomNamedGetter();
}

JSTestCustomNamedGetter::~JSTestCustomNamedGetter()
{
    releaseImplIfNotNull();
}

bool JSTestCustomNamedGetter::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestCustomNamedGetter* thisObject = jsCast<JSTestCustomNamedGetter*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (canGetItemsForName(exec, &thisObject->impl(), propertyName)) {
        slot.setCustom(thisObject, ReadOnly | DontDelete | DontEnum, thisObject->nameGetter);
        return true;
    }
    return getStaticValueSlot<JSTestCustomNamedGetter, Base>(exec, JSTestCustomNamedGetterTable, thisObject, propertyName, slot);
}

bool JSTestCustomNamedGetter::getOwnPropertySlotByIndex(JSObject* object, ExecState* exec, unsigned index, PropertySlot& slot)
{
    JSTestCustomNamedGetter* thisObject = jsCast<JSTestCustomNamedGetter*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    PropertyName propertyName = Identifier::from(exec, index);
    if (canGetItemsForName(exec, &thisObject->impl(), propertyName)) {
        slot.setCustom(thisObject, ReadOnly | DontDelete | DontEnum, thisObject->nameGetter);
        return true;
    }
    return Base::getOwnPropertySlotByIndex(thisObject, exec, index, slot);
}

EncodedJSValue jsTestCustomNamedGetterConstructor(ExecState* exec, JSObject*, EncodedJSValue thisValue, PropertyName)
{
    JSTestCustomNamedGetter* domObject = jsDynamicCast<JSTestCustomNamedGetter*>(JSValue::decode(thisValue));
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSTestCustomNamedGetter::getConstructor(exec->vm(), domObject->globalObject()));
}

JSValue JSTestCustomNamedGetter::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestCustomNamedGetterConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsTestCustomNamedGetterPrototypeFunctionAnotherFunction(ExecState* exec)
{
    JSValue thisValue = exec->thisValue();
    JSTestCustomNamedGetter* castedThis = jsDynamicCast<JSTestCustomNamedGetter*>(thisValue);
    if (UNLIKELY(!castedThis))
        return throwThisTypeError(*exec, "TestCustomNamedGetter", "anotherFunction");
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSTestCustomNamedGetter::info());
    TestCustomNamedGetter& impl = castedThis->impl();
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createNotEnoughArgumentsError(exec));
    const String& str(exec->argument(0).isEmpty() ? String() : exec->argument(0).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    impl.anotherFunction(str);
    return JSValue::encode(jsUndefined());
}

bool JSTestCustomNamedGetterOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestCustomNamedGetterOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSTestCustomNamedGetter* jsTestCustomNamedGetter = jsCast<JSTestCustomNamedGetter*>(handle.slot()->asCell());
    DOMWrapperWorld& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestCustomNamedGetter->impl(), jsTestCustomNamedGetter);
    jsTestCustomNamedGetter->releaseImpl();
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestCustomNamedGetter@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore21TestCustomNamedGetterE[]; }
#endif
#endif
JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject* globalObject, TestCustomNamedGetter* impl)
{
    if (!impl)
        return jsNull();
    if (JSValue result = getExistingWrapper<JSTestCustomNamedGetter>(globalObject, impl))
        return result;

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestCustomNamedGetter@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore21TestCustomNamedGetterE[2];
#if COMPILER(CLANG)
    // If this fails TestCustomNamedGetter does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    COMPILE_ASSERT(__is_polymorphic(TestCustomNamedGetter), TestCustomNamedGetter_is_not_polymorphic);
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestCustomNamedGetter has subclasses. If TestCustomNamedGetter has subclasses that get passed
    // to toJS() we currently require TestCustomNamedGetter you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createNewWrapper<JSTestCustomNamedGetter>(globalObject, impl);
}

TestCustomNamedGetter* toTestCustomNamedGetter(JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestCustomNamedGetter*>(value))
        return &wrapper->impl();
    return nullptr;
}

}
