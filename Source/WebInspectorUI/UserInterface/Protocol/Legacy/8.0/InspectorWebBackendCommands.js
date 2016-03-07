/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 * Copyright (C) 2013, 2014 Apple Inc. All rights reserved.
 * Copyright (C) 2014 University of Washington. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

// DO NOT EDIT THIS FILE. It is automatically generated from InspectorWeb-iOS-8.0.json
// by the script: Source/JavaScriptCore/inspector/scripts/generate-inspector-protocol-bindings.py

// ApplicationCache.
InspectorBackend.registerApplicationCacheDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "ApplicationCache");
InspectorBackend.registerEvent("ApplicationCache.applicationCacheStatusUpdated", ["frameId", "manifestURL", "status"]);
InspectorBackend.registerEvent("ApplicationCache.networkStateUpdated", ["isNowOnline"]);
InspectorBackend.registerCommand("ApplicationCache.getFramesWithManifests", [], ["frameIds"]);
InspectorBackend.registerCommand("ApplicationCache.enable", [], []);
InspectorBackend.registerCommand("ApplicationCache.getManifestForFrame", [{"name": "frameId", "type": "string", "optional": false}], ["manifestURL"]);
InspectorBackend.registerCommand("ApplicationCache.getApplicationCacheForFrame", [{"name": "frameId", "type": "string", "optional": false}], ["applicationCache"]);

// CSS.
InspectorBackend.registerCSSDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "CSS");
InspectorBackend.registerEnum("CSS.StyleSheetOrigin", {User: "user", UserAgent: "user-agent", Inspector: "inspector", Regular: "regular"});
InspectorBackend.registerEnum("CSS.CSSPropertyStatus", {Active: "active", Inactive: "inactive", Disabled: "disabled", Style: "style"});
InspectorBackend.registerEnum("CSS.CSSMediaSource", {MediaRule: "mediaRule", ImportRule: "importRule", LinkedSheet: "linkedSheet", InlineSheet: "inlineSheet"});
InspectorBackend.registerEnum("CSS.RegionRegionOverset", {Overset: "overset", Fit: "fit", Empty: "empty"});
InspectorBackend.registerEvent("CSS.mediaQueryResultChanged", []);
InspectorBackend.registerEvent("CSS.styleSheetChanged", ["styleSheetId"]);
InspectorBackend.registerEvent("CSS.namedFlowCreated", ["namedFlow"]);
InspectorBackend.registerEvent("CSS.namedFlowRemoved", ["documentNodeId", "flowName"]);
InspectorBackend.registerEvent("CSS.regionOversetChanged", ["namedFlow"]);
InspectorBackend.registerEvent("CSS.registeredNamedFlowContentElement", ["documentNodeId", "flowName", "contentNodeId", "nextContentNodeId"]);
InspectorBackend.registerEvent("CSS.unregisteredNamedFlowContentElement", ["documentNodeId", "flowName", "contentNodeId"]);
InspectorBackend.registerCommand("CSS.enable", [], []);
InspectorBackend.registerCommand("CSS.disable", [], []);
InspectorBackend.registerCommand("CSS.getMatchedStylesForNode", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "includePseudo", "type": "boolean", "optional": true}, {"name": "includeInherited", "type": "boolean", "optional": true}], ["matchedCSSRules", "pseudoElements", "inherited"]);
InspectorBackend.registerCommand("CSS.getInlineStylesForNode", [{"name": "nodeId", "type": "number", "optional": false}], ["inlineStyle", "attributesStyle"]);
InspectorBackend.registerCommand("CSS.getComputedStyleForNode", [{"name": "nodeId", "type": "number", "optional": false}], ["computedStyle"]);
InspectorBackend.registerCommand("CSS.getAllStyleSheets", [], ["headers"]);
InspectorBackend.registerCommand("CSS.getStyleSheet", [{"name": "styleSheetId", "type": "string", "optional": false}], ["styleSheet"]);
InspectorBackend.registerCommand("CSS.getStyleSheetText", [{"name": "styleSheetId", "type": "string", "optional": false}], ["text"]);
InspectorBackend.registerCommand("CSS.setStyleSheetText", [{"name": "styleSheetId", "type": "string", "optional": false}, {"name": "text", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("CSS.setStyleText", [{"name": "styleId", "type": "object", "optional": false}, {"name": "text", "type": "string", "optional": false}], ["style"]);
InspectorBackend.registerCommand("CSS.setPropertyText", [{"name": "styleId", "type": "object", "optional": false}, {"name": "propertyIndex", "type": "number", "optional": false}, {"name": "text", "type": "string", "optional": false}, {"name": "overwrite", "type": "boolean", "optional": false}], ["style"]);
InspectorBackend.registerCommand("CSS.toggleProperty", [{"name": "styleId", "type": "object", "optional": false}, {"name": "propertyIndex", "type": "number", "optional": false}, {"name": "disable", "type": "boolean", "optional": false}], ["style"]);
InspectorBackend.registerCommand("CSS.setRuleSelector", [{"name": "ruleId", "type": "object", "optional": false}, {"name": "selector", "type": "string", "optional": false}], ["rule"]);
InspectorBackend.registerCommand("CSS.addRule", [{"name": "contextNodeId", "type": "number", "optional": false}, {"name": "selector", "type": "string", "optional": false}], ["rule"]);
InspectorBackend.registerCommand("CSS.getSupportedCSSProperties", [], ["cssProperties"]);
InspectorBackend.registerCommand("CSS.forcePseudoState", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "forcedPseudoClasses", "type": "object", "optional": false}], []);
InspectorBackend.registerCommand("CSS.getNamedFlowCollection", [{"name": "documentNodeId", "type": "number", "optional": false}], ["namedFlows"]);

// DOM.
InspectorBackend.registerDOMDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "DOM");
InspectorBackend.registerEnum("DOM.LiveRegionRelevant", {Additions: "additions", Removals: "removals", Text: "text"});
InspectorBackend.registerEnum("DOM.AccessibilityPropertiesChecked", {True: "true", False: "false", Mixed: "mixed"});
InspectorBackend.registerEnum("DOM.AccessibilityPropertiesInvalid", {True: "true", False: "false", Grammar: "grammar", Spelling: "spelling"});
InspectorBackend.registerEnum("DOM.AccessibilityPropertiesLiveRegionStatus", {Assertive: "assertive", Polite: "polite", Off: "off"});
InspectorBackend.registerEvent("DOM.documentUpdated", []);
InspectorBackend.registerEvent("DOM.setChildNodes", ["parentId", "nodes"]);
InspectorBackend.registerEvent("DOM.attributeModified", ["nodeId", "name", "value"]);
InspectorBackend.registerEvent("DOM.attributeRemoved", ["nodeId", "name"]);
InspectorBackend.registerEvent("DOM.inlineStyleInvalidated", ["nodeIds"]);
InspectorBackend.registerEvent("DOM.characterDataModified", ["nodeId", "characterData"]);
InspectorBackend.registerEvent("DOM.childNodeCountUpdated", ["nodeId", "childNodeCount"]);
InspectorBackend.registerEvent("DOM.childNodeInserted", ["parentNodeId", "previousNodeId", "node"]);
InspectorBackend.registerEvent("DOM.childNodeRemoved", ["parentNodeId", "nodeId"]);
InspectorBackend.registerEvent("DOM.shadowRootPushed", ["hostId", "root"]);
InspectorBackend.registerEvent("DOM.shadowRootPopped", ["hostId", "rootId"]);
InspectorBackend.registerCommand("DOM.getDocument", [], ["root"]);
InspectorBackend.registerCommand("DOM.requestChildNodes", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "depth", "type": "number", "optional": true}], []);
InspectorBackend.registerCommand("DOM.querySelector", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "selector", "type": "string", "optional": false}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.querySelectorAll", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "selector", "type": "string", "optional": false}], ["nodeIds"]);
InspectorBackend.registerCommand("DOM.setNodeName", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "name", "type": "string", "optional": false}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.setNodeValue", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "value", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.removeNode", [{"name": "nodeId", "type": "number", "optional": false}], []);
InspectorBackend.registerCommand("DOM.setAttributeValue", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "name", "type": "string", "optional": false}, {"name": "value", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.setAttributesAsText", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "text", "type": "string", "optional": false}, {"name": "name", "type": "string", "optional": true}], []);
InspectorBackend.registerCommand("DOM.removeAttribute", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "name", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.getEventListenersForNode", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "objectGroup", "type": "string", "optional": true}], ["listeners"]);
InspectorBackend.registerCommand("DOM.getAccessibilityPropertiesForNode", [{"name": "nodeId", "type": "number", "optional": false}], ["properties"]);
InspectorBackend.registerCommand("DOM.getOuterHTML", [{"name": "nodeId", "type": "number", "optional": false}], ["outerHTML"]);
InspectorBackend.registerCommand("DOM.setOuterHTML", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "outerHTML", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.performSearch", [{"name": "query", "type": "string", "optional": false}, {"name": "nodeIds", "type": "object", "optional": true}], ["searchId", "resultCount"]);
InspectorBackend.registerCommand("DOM.getSearchResults", [{"name": "searchId", "type": "string", "optional": false}, {"name": "fromIndex", "type": "number", "optional": false}, {"name": "toIndex", "type": "number", "optional": false}], ["nodeIds"]);
InspectorBackend.registerCommand("DOM.discardSearchResults", [{"name": "searchId", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.requestNode", [{"name": "objectId", "type": "string", "optional": false}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.setInspectModeEnabled", [{"name": "enabled", "type": "boolean", "optional": false}, {"name": "highlightConfig", "type": "object", "optional": true}], []);
InspectorBackend.registerCommand("DOM.highlightRect", [{"name": "x", "type": "number", "optional": false}, {"name": "y", "type": "number", "optional": false}, {"name": "width", "type": "number", "optional": false}, {"name": "height", "type": "number", "optional": false}, {"name": "color", "type": "object", "optional": true}, {"name": "outlineColor", "type": "object", "optional": true}, {"name": "usePageCoordinates", "type": "boolean", "optional": true}], []);
InspectorBackend.registerCommand("DOM.highlightQuad", [{"name": "quad", "type": "object", "optional": false}, {"name": "color", "type": "object", "optional": true}, {"name": "outlineColor", "type": "object", "optional": true}, {"name": "usePageCoordinates", "type": "boolean", "optional": true}], []);
InspectorBackend.registerCommand("DOM.highlightNode", [{"name": "highlightConfig", "type": "object", "optional": false}, {"name": "nodeId", "type": "number", "optional": true}, {"name": "objectId", "type": "string", "optional": true}], []);
InspectorBackend.registerCommand("DOM.hideHighlight", [], []);
InspectorBackend.registerCommand("DOM.highlightFrame", [{"name": "frameId", "type": "string", "optional": false}, {"name": "contentColor", "type": "object", "optional": true}, {"name": "contentOutlineColor", "type": "object", "optional": true}], []);
InspectorBackend.registerCommand("DOM.pushNodeByPathToFrontend", [{"name": "path", "type": "string", "optional": false}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.pushNodeByBackendIdToFrontend", [{"name": "backendNodeId", "type": "number", "optional": false}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.releaseBackendNodeIds", [{"name": "nodeGroup", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOM.resolveNode", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "objectGroup", "type": "string", "optional": true}], ["object"]);
InspectorBackend.registerCommand("DOM.getAttributes", [{"name": "nodeId", "type": "number", "optional": false}], ["attributes"]);
InspectorBackend.registerCommand("DOM.moveTo", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "targetNodeId", "type": "number", "optional": false}, {"name": "insertBeforeNodeId", "type": "number", "optional": true}], ["nodeId"]);
InspectorBackend.registerCommand("DOM.undo", [], []);
InspectorBackend.registerCommand("DOM.redo", [], []);
InspectorBackend.registerCommand("DOM.markUndoableState", [], []);
InspectorBackend.registerCommand("DOM.focus", [{"name": "nodeId", "type": "number", "optional": false}], []);

// DOMDebugger.
InspectorBackend.registerEnum("DOMDebugger.DOMBreakpointType", {SubtreeModified: "subtree-modified", AttributeModified: "attribute-modified", NodeRemoved: "node-removed"});
InspectorBackend.registerCommand("DOMDebugger.setDOMBreakpoint", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "type", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.removeDOMBreakpoint", [{"name": "nodeId", "type": "number", "optional": false}, {"name": "type", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.setEventListenerBreakpoint", [{"name": "eventName", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.removeEventListenerBreakpoint", [{"name": "eventName", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.setInstrumentationBreakpoint", [{"name": "eventName", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.removeInstrumentationBreakpoint", [{"name": "eventName", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.setXHRBreakpoint", [{"name": "url", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMDebugger.removeXHRBreakpoint", [{"name": "url", "type": "string", "optional": false}], []);

// DOMStorage.
InspectorBackend.registerDOMStorageDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "DOMStorage");
InspectorBackend.registerEvent("DOMStorage.domStorageItemsCleared", ["storageId"]);
InspectorBackend.registerEvent("DOMStorage.domStorageItemRemoved", ["storageId", "key"]);
InspectorBackend.registerEvent("DOMStorage.domStorageItemAdded", ["storageId", "key", "newValue"]);
InspectorBackend.registerEvent("DOMStorage.domStorageItemUpdated", ["storageId", "key", "oldValue", "newValue"]);
InspectorBackend.registerCommand("DOMStorage.enable", [], []);
InspectorBackend.registerCommand("DOMStorage.disable", [], []);
InspectorBackend.registerCommand("DOMStorage.getDOMStorageItems", [{"name": "storageId", "type": "object", "optional": false}], ["entries"]);
InspectorBackend.registerCommand("DOMStorage.setDOMStorageItem", [{"name": "storageId", "type": "object", "optional": false}, {"name": "key", "type": "string", "optional": false}, {"name": "value", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("DOMStorage.removeDOMStorageItem", [{"name": "storageId", "type": "object", "optional": false}, {"name": "key", "type": "string", "optional": false}], []);

// Database.
InspectorBackend.registerDatabaseDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "Database");
InspectorBackend.registerEvent("Database.addDatabase", ["database"]);
InspectorBackend.registerCommand("Database.enable", [], []);
InspectorBackend.registerCommand("Database.disable", [], []);
InspectorBackend.registerCommand("Database.getDatabaseTableNames", [{"name": "databaseId", "type": "string", "optional": false}], ["tableNames"]);
InspectorBackend.registerCommand("Database.executeSQL", [{"name": "databaseId", "type": "string", "optional": false}, {"name": "query", "type": "string", "optional": false}], ["columnNames", "values", "sqlError"]);

// IndexedDB.
InspectorBackend.registerIndexedDBDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "IndexedDB");
InspectorBackend.registerEnum("IndexedDB.KeyType", {Number: "number", String: "string", Date: "date", Array: "array"});
InspectorBackend.registerEnum("IndexedDB.KeyPathType", {Null: "null", String: "string", Array: "array"});
InspectorBackend.registerCommand("IndexedDB.enable", [], []);
InspectorBackend.registerCommand("IndexedDB.disable", [], []);
InspectorBackend.registerCommand("IndexedDB.requestDatabaseNames", [{"name": "securityOrigin", "type": "string", "optional": false}], ["databaseNames"]);
InspectorBackend.registerCommand("IndexedDB.requestDatabase", [{"name": "securityOrigin", "type": "string", "optional": false}, {"name": "databaseName", "type": "string", "optional": false}], ["databaseWithObjectStores"]);
InspectorBackend.registerCommand("IndexedDB.requestData", [{"name": "securityOrigin", "type": "string", "optional": false}, {"name": "databaseName", "type": "string", "optional": false}, {"name": "objectStoreName", "type": "string", "optional": false}, {"name": "indexName", "type": "string", "optional": false}, {"name": "skipCount", "type": "number", "optional": false}, {"name": "pageSize", "type": "number", "optional": false}, {"name": "keyRange", "type": "object", "optional": true}], ["objectStoreDataEntries", "hasMore"]);
InspectorBackend.registerCommand("IndexedDB.clearObjectStore", [{"name": "securityOrigin", "type": "string", "optional": false}, {"name": "databaseName", "type": "string", "optional": false}, {"name": "objectStoreName", "type": "string", "optional": false}], []);

// LayerTree.
InspectorBackend.registerLayerTreeDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "LayerTree");
InspectorBackend.registerEvent("LayerTree.layerTreeDidChange", []);
InspectorBackend.registerCommand("LayerTree.enable", [], []);
InspectorBackend.registerCommand("LayerTree.disable", [], []);
InspectorBackend.registerCommand("LayerTree.layersForNode", [{"name": "nodeId", "type": "number", "optional": false}], ["layers"]);
InspectorBackend.registerCommand("LayerTree.reasonsForCompositingLayer", [{"name": "layerId", "type": "string", "optional": false}], ["compositingReasons"]);

// Network.
InspectorBackend.registerNetworkDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "Network");
InspectorBackend.registerEnum("Network.InitiatorType", {Parser: "parser", Script: "script", Other: "other"});
InspectorBackend.registerEvent("Network.requestWillBeSent", ["requestId", "frameId", "loaderId", "documentURL", "request", "timestamp", "initiator", "redirectResponse", "type"]);
InspectorBackend.registerEvent("Network.requestServedFromCache", ["requestId"]);
InspectorBackend.registerEvent("Network.responseReceived", ["requestId", "frameId", "loaderId", "timestamp", "type", "response"]);
InspectorBackend.registerEvent("Network.dataReceived", ["requestId", "timestamp", "dataLength", "encodedDataLength"]);
InspectorBackend.registerEvent("Network.loadingFinished", ["requestId", "timestamp", "sourceMapURL"]);
InspectorBackend.registerEvent("Network.loadingFailed", ["requestId", "timestamp", "errorText", "canceled"]);
InspectorBackend.registerEvent("Network.requestServedFromMemoryCache", ["requestId", "frameId", "loaderId", "documentURL", "timestamp", "initiator", "resource"]);
InspectorBackend.registerEvent("Network.webSocketWillSendHandshakeRequest", ["requestId", "timestamp", "request"]);
InspectorBackend.registerEvent("Network.webSocketHandshakeResponseReceived", ["requestId", "timestamp", "response"]);
InspectorBackend.registerEvent("Network.webSocketCreated", ["requestId", "url"]);
InspectorBackend.registerEvent("Network.webSocketClosed", ["requestId", "timestamp"]);
InspectorBackend.registerEvent("Network.webSocketFrameReceived", ["requestId", "timestamp", "response"]);
InspectorBackend.registerEvent("Network.webSocketFrameError", ["requestId", "timestamp", "errorMessage"]);
InspectorBackend.registerEvent("Network.webSocketFrameSent", ["requestId", "timestamp", "response"]);
InspectorBackend.registerCommand("Network.enable", [], []);
InspectorBackend.registerCommand("Network.disable", [], []);
InspectorBackend.registerCommand("Network.setExtraHTTPHeaders", [{"name": "headers", "type": "object", "optional": false}], []);
InspectorBackend.registerCommand("Network.getResponseBody", [{"name": "requestId", "type": "string", "optional": false}], ["body", "base64Encoded"]);
InspectorBackend.registerCommand("Network.replayXHR", [{"name": "requestId", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Network.canClearBrowserCache", [], ["result"]);
InspectorBackend.registerCommand("Network.clearBrowserCache", [], []);
InspectorBackend.registerCommand("Network.canClearBrowserCookies", [], ["result"]);
InspectorBackend.registerCommand("Network.clearBrowserCookies", [], []);
InspectorBackend.registerCommand("Network.setCacheDisabled", [{"name": "cacheDisabled", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Network.loadResource", [{"name": "frameId", "type": "string", "optional": false}, {"name": "url", "type": "string", "optional": false}], ["content", "mimeType", "status"]);

// Page.
InspectorBackend.registerPageDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "Page");
InspectorBackend.registerEnum("Page.ResourceType", {Document: "Document", Stylesheet: "Stylesheet", Image: "Image", Font: "Font", Script: "Script", XHR: "XHR", WebSocket: "WebSocket", Other: "Other"});
InspectorBackend.registerEnum("Page.CoordinateSystem", {Viewport: "Viewport", Page: "Page"});
InspectorBackend.registerEvent("Page.domContentEventFired", ["timestamp"]);
InspectorBackend.registerEvent("Page.loadEventFired", ["timestamp"]);
InspectorBackend.registerEvent("Page.frameNavigated", ["frame"]);
InspectorBackend.registerEvent("Page.frameDetached", ["frameId"]);
InspectorBackend.registerEvent("Page.frameStartedLoading", ["frameId"]);
InspectorBackend.registerEvent("Page.frameStoppedLoading", ["frameId"]);
InspectorBackend.registerEvent("Page.frameScheduledNavigation", ["frameId", "delay"]);
InspectorBackend.registerEvent("Page.frameClearedScheduledNavigation", ["frameId"]);
InspectorBackend.registerEvent("Page.javascriptDialogOpening", ["message"]);
InspectorBackend.registerEvent("Page.javascriptDialogClosed", []);
InspectorBackend.registerEvent("Page.scriptsEnabled", ["isEnabled"]);
InspectorBackend.registerCommand("Page.enable", [], []);
InspectorBackend.registerCommand("Page.disable", [], []);
InspectorBackend.registerCommand("Page.addScriptToEvaluateOnLoad", [{"name": "scriptSource", "type": "string", "optional": false}], ["identifier"]);
InspectorBackend.registerCommand("Page.removeScriptToEvaluateOnLoad", [{"name": "identifier", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Page.reload", [{"name": "ignoreCache", "type": "boolean", "optional": true}, {"name": "scriptToEvaluateOnLoad", "type": "string", "optional": true}], []);
InspectorBackend.registerCommand("Page.navigate", [{"name": "url", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Page.getCookies", [], ["cookies"]);
InspectorBackend.registerCommand("Page.deleteCookie", [{"name": "cookieName", "type": "string", "optional": false}, {"name": "url", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Page.getResourceTree", [], ["frameTree"]);
InspectorBackend.registerCommand("Page.getResourceContent", [{"name": "frameId", "type": "string", "optional": false}, {"name": "url", "type": "string", "optional": false}], ["content", "base64Encoded"]);
InspectorBackend.registerCommand("Page.searchInResource", [{"name": "frameId", "type": "string", "optional": false}, {"name": "url", "type": "string", "optional": false}, {"name": "query", "type": "string", "optional": false}, {"name": "caseSensitive", "type": "boolean", "optional": true}, {"name": "isRegex", "type": "boolean", "optional": true}], ["result"]);
InspectorBackend.registerCommand("Page.searchInResources", [{"name": "text", "type": "string", "optional": false}, {"name": "caseSensitive", "type": "boolean", "optional": true}, {"name": "isRegex", "type": "boolean", "optional": true}], ["result"]);
InspectorBackend.registerCommand("Page.setDocumentContent", [{"name": "frameId", "type": "string", "optional": false}, {"name": "html", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Page.setShowPaintRects", [{"name": "result", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.canShowDebugBorders", [], ["show"]);
InspectorBackend.registerCommand("Page.setShowDebugBorders", [{"name": "show", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.canShowFPSCounter", [], ["show"]);
InspectorBackend.registerCommand("Page.setShowFPSCounter", [{"name": "show", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.canContinuouslyPaint", [], ["value"]);
InspectorBackend.registerCommand("Page.setContinuousPaintingEnabled", [{"name": "enabled", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.getScriptExecutionStatus", [], ["result"]);
InspectorBackend.registerCommand("Page.setScriptExecutionDisabled", [{"name": "value", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.setTouchEmulationEnabled", [{"name": "enabled", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.setEmulatedMedia", [{"name": "media", "type": "string", "optional": false}], []);
InspectorBackend.registerCommand("Page.getCompositingBordersVisible", [], ["result"]);
InspectorBackend.registerCommand("Page.setCompositingBordersVisible", [{"name": "visible", "type": "boolean", "optional": false}], []);
InspectorBackend.registerCommand("Page.snapshotNode", [{"name": "nodeId", "type": "number", "optional": false}], ["dataURL"]);
InspectorBackend.registerCommand("Page.snapshotRect", [{"name": "x", "type": "number", "optional": false}, {"name": "y", "type": "number", "optional": false}, {"name": "width", "type": "number", "optional": false}, {"name": "height", "type": "number", "optional": false}, {"name": "coordinateSystem", "type": "string", "optional": false}], ["dataURL"]);
InspectorBackend.registerCommand("Page.handleJavaScriptDialog", [{"name": "accept", "type": "boolean", "optional": false}, {"name": "promptText", "type": "string", "optional": true}], []);
InspectorBackend.registerCommand("Page.archive", [], ["data"]);

// Timeline.
InspectorBackend.registerTimelineDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "Timeline");
InspectorBackend.registerEnum("Timeline.EventType", {EventDispatch: "EventDispatch", ScheduleStyleRecalculation: "ScheduleStyleRecalculation", RecalculateStyles: "RecalculateStyles", InvalidateLayout: "InvalidateLayout", Layout: "Layout", Paint: "Paint", ScrollLayer: "ScrollLayer", ResizeImage: "ResizeImage", ParseHTML: "ParseHTML", TimerInstall: "TimerInstall", TimerRemove: "TimerRemove", TimerFire: "TimerFire", EvaluateScript: "EvaluateScript", MarkLoad: "MarkLoad", MarkDOMContent: "MarkDOMContent", TimeStamp: "TimeStamp", Time: "Time", TimeEnd: "TimeEnd", ScheduleResourceRequest: "ScheduleResourceRequest", ResourceSendRequest: "ResourceSendRequest", ResourceReceiveResponse: "ResourceReceiveResponse", ResourceReceivedData: "ResourceReceivedData", ResourceFinish: "ResourceFinish", XHRReadyStateChange: "XHRReadyStateChange", XHRLoad: "XHRLoad", FunctionCall: "FunctionCall", ProbeSample: "ProbeSample", ConsoleProfile: "ConsoleProfile", GCEvent: "GCEvent", RequestAnimationFrame: "RequestAnimationFrame", CancelAnimationFrame: "CancelAnimationFrame", FireAnimationFrame: "FireAnimationFrame", WebSocketCreate: "WebSocketCreate", WebSocketSendHandshakeRequest: "WebSocketSendHandshakeRequest", WebSocketReceiveHandshakeResponse: "WebSocketReceiveHandshakeResponse", WebSocketDestroy: "WebSocketDestroy"});
InspectorBackend.registerEvent("Timeline.eventRecorded", ["record"]);
InspectorBackend.registerEvent("Timeline.recordingStarted", []);
InspectorBackend.registerEvent("Timeline.recordingStopped", []);
InspectorBackend.registerCommand("Timeline.start", [{"name": "maxCallStackDepth", "type": "number", "optional": true}], []);
InspectorBackend.registerCommand("Timeline.stop", [], []);

// Worker.
InspectorBackend.registerWorkerDispatcher = InspectorBackend.registerDomainDispatcher.bind(InspectorBackend, "Worker");
InspectorBackend.registerEvent("Worker.workerCreated", ["workerId", "url", "inspectorConnected"]);
InspectorBackend.registerEvent("Worker.workerTerminated", ["workerId"]);
InspectorBackend.registerEvent("Worker.dispatchMessageFromWorker", ["workerId", "message"]);
InspectorBackend.registerEvent("Worker.disconnectedFromWorker", []);
InspectorBackend.registerCommand("Worker.enable", [], []);
InspectorBackend.registerCommand("Worker.disable", [], []);
InspectorBackend.registerCommand("Worker.sendMessageToWorker", [{"name": "workerId", "type": "number", "optional": false}, {"name": "message", "type": "object", "optional": false}], []);
InspectorBackend.registerCommand("Worker.canInspectWorkers", [], ["result"]);
InspectorBackend.registerCommand("Worker.connectToWorker", [{"name": "workerId", "type": "number", "optional": false}], []);
InspectorBackend.registerCommand("Worker.disconnectFromWorker", [{"name": "workerId", "type": "number", "optional": false}], []);
InspectorBackend.registerCommand("Worker.setAutoconnectToWorkers", [{"name": "value", "type": "boolean", "optional": false}], []);
