(function(){
  'use strict';
  const V2_KEY='gym-management-system:v2',V1_KEY='gym-management-system:v1';
  window.Gym=window.Gym||{};
  function parse(key){const raw=localStorage.getItem(key);if(!raw)return null;try{return JSON.parse(raw)}catch(error){localStorage.setItem(`${key}:corrupt:${Date.now()}`,raw);return null}}
  Gym.Storage={KEY:V2_KEY,V1_KEY,load(){const v2=parse(V2_KEY);if(v2?.version===2)return v2;return null},loadV1(){const v1=parse(V1_KEY);return v1?.version===1?v1:null},save(data){try{localStorage.setItem(V2_KEY,JSON.stringify(data));return true}catch(error){Gym.UI?.toast('Unable to save data. Browser storage may be full.','error');return false}},export(){return JSON.stringify({schemaVersion:2,exportedAt:new Date().toISOString(),applicationState:Gym.state,settings:Gym.state.settings,metadata:Gym.state.metadata},null,2)}};
})();
