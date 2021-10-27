import { createRouter, createWebHistory } from 'vue-router'
import Home from '../views/Home.vue'
import About from '../views/About.vue'
import Cadastro from '../views/Cadastro.vue'
 
const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/about',
    name: 'About',
    component: About
  },{
    path: "/victor",
    name: 'Victor',
    component: Cadastro,
    children: [
      {
        path: "hugo",
        component: About,
        name: "Hugo"
      }
    ]
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router
