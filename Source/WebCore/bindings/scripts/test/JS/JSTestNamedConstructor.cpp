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
#include "JSTestNamedConstructor.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "TestNamedConstructor.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table for constructor */

static const struct CompactHashIndex JSTestNamedConstructorConstructorTableIndex[1] = {
    { -1, -1 },
};


static const HashTableValue JSTestNamedConstructorConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTestNamedConstructorConstructorTable = { 0, 0, false, JSTestNamedConstructorConstructorTableValues, 0, JSTestNamedConstructorConstructorTableIndex };
const ClassInfo JSTestNamedConstructorConstructor::s_info = { "TestNamedConstructorConstructor", &Base::s_info, &JSTestNamedConstructorConstructorTable, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorConstructor) };

JSTestNamedConstructorConstructor::JSTestNamedConstructorConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestNamedConstructorConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedConstructorPrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSTestNamedConstructorConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestNamedConstructorConstructor, JSDOMWrapper>(exec, JSTestNamedConstructorConstructorTable, jsCast<JSTestNamedConstructorConstructor*>(object), propertyName, slot);
}

EncodedJSValue JSC_HOST_CALL JSTestNamedConstructorNamedConstructor::constructJSTestNamedConstructor(ExecState* exec)
{
    JSTestNamedConstructorNamedConstructor* castedThis = jsCast<JSTestNamedConstructorNamedConstructor*>(exec->callee());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createNotEnoughArgumentsError(exec));
    ExceptionCode ec = 0;
    const String& str1(exec->argument(0).isEmpty() ? String() : exec->argument(0).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    const String& str2(exec->argument(1).isEmpty() ? String() : exec->argument(1).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    const String& str3(argumentOrNull(exec, 2).isEmpty() ? String() : argumentOrNull(exec, 2).toString(exec)->value(exec));
    if (UNLIKELY(exec->hadException()))
        return JSValue::encode(jsUndefined());
    RefPtr<TestNamedConstructor> object = TestNamedConstructor::createForJSConstructor(*castedThis->document(), str1, str2, str3, ec);
    if (ec) {
        setDOMException(exec, ec);
        return JSValue::encode(JSValue());
    }
    return JSValue::encode(asObject(toJS(exec, castedThis->globalObject(), object.get())));
}

const ClassInfo JSTestNamedConstructorNamedConstructor::s_info = { "AudioConstructor", &Base::s_info, 0, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorNamedConstructor) };

JSTestNamedConstructorNamedConstructor::JSTestNamedConstructorNamedConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorWithDocument(structure, globalObject)
{
}

void JSTestNamedConstructorNamedConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(globalObject);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedConstructorPrototype::self(vm, globalObject), None);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

ConstructType JSTestNamedConstructorNamedConstructor::getConstructData(JSCell*, ConstructData& constructData)
{
    constructData.native.function = constructJSTestNamedConstructor;
    return ConstructTypeHost;
}

/* Hash table for prototype */

static const struct CompactHashIndex JSTestNamedConstructorPrototypeTableIndex[2] = {
    { -1, -1 },
    { 0, -1 },
};


static const HashTableValue JSTestNamedConstructorPrototypeTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNamedConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) },
};

static const HashTable JSTestNamedConstructorPrototypeTable = { 1, 1, true, JSTestNamedConstructorPrototypeTableValues, 0, JSTestNamedConstructorPrototypeTableIndex };
const ClassInfo JSTestNamedConstructorPrototype::s_info = { "TestNamedConstructorPrototype", &Base::s_info, &JSTestNamedConstructorPrototypeTable, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorPrototype) };

JSObject* JSTestNamedConstructorPrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestNamedConstructor>(vm, globalObject);
}

void JSTestNamedConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestNamedConstructorPrototypeTable, this);
}

const ClassInfo JSTestNamedConstructor::s_info = { "TestNamedConstructor", &Base::s_info, 0, 0 , CREATE_METHOD_TABLE(JSTestNamedConstructor) };

JSTestNamedConstructor::JSTestNamedConstructor(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestNamedConstructor> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl.leakRef())
{
}

JSObject* JSTestNamedConstructor::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSTestNamedConstructorPrototype::create(vm, globalObject, JSTestNamedConstructorPrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));
}

void JSTestNamedConstructor::destroy(JSC::JSCell* cell)
{
    JSTestNamedConstructor* thisObject = static_cast<JSTestNamedConstructor*>(cell);
    thisObject->JSTestNamedConstructor::~JSTestNamedConstructor();
}

JSTestNamedConstructor::~JSTestNamedConstructor()
{
    releaseImplIfNotNull();
}

EncodedJSValue jsTestNamedConstructorConstructor(ExecState* exec, JSObject* baseValue, EncodedJSValue, PropertyName)
{
    JSTestNamedConstructorPrototype* domObject = jsDynamicCast<JSTestNamedConstructorPrototype*>(baseValue);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSTestNamedConstructor::getConstructor(exec->vm(), domObject->globalObject()));
}

JSValue JSTestNamedConstructor::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedConstructorConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSTestNamedConstructor::getNamedConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedConstructorNamedConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

bool JSTestNamedConstructorOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    JSTestNamedConstructor* jsTestNamedConstructor = jsCast<JSTestNamedConstructor*>(handle.slot()->asCell());
    if (jsTestNamedConstructor->impl().hasPendingActivity())
        return true;
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestNamedConstructorOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSTestNamedConstructor* jsTestNamedConstructor = jsCast<JSTestNamedConstructor*>(handle.slot()->asCell());
    DOMWrapperWorld& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestNamedConstructor->impl(), jsTestNamedConstructor);
    jsTestNamedConstructor->releaseImpl();
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestNamedConstructorE[]; }
#endif
#endif
JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject* globalObject, TestNamedConstructor* impl)
{
    if (!impl)
        return jsNull();
    if (JSValue result = getExistingWrapper<JSTestNamedConstructor>(globalObject, impl))
        return result;

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestNamedConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestNamedConstructorE[2];
#if COMPILER(CLANG)
    // If this fails TestNamedConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    COMPILE_ASSERT(__is_polymorphic(TestNamedConstructor), TestNamedConstructor_is_not_polymorphic);
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestNamedConstructor has subclasses. If TestNamedConstructor has subclasses that get passed
    // to toJS() we currently require TestNamedConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createNewWrapper<JSTestNamedConstructor>(globalObject, impl);
}

TestNamedConstructor* toTestNamedConstructor(JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestNamedConstructor*>(value))
        return &wrapper->impl();
    return nullptr;
}

}
