# Most common and important React hooks:
* **useState:** This is the most essential hook, used to add state management to functional components. It returns a state value and a function to update that value, causing the component to re-render when the state changes. It's used for managing things like form inputs, counters, and toggles.
* **useEffect:** This hook allows you to perform side effects in your components, such as data fetching, subscriptions, or manually changing the DOM. The effect runs after the component renders and can be controlled with an optional dependency array to run only when specific values change.
* **useContext:** This hook simplifies accessing values from the React Context API, which avoids the need for "prop drilling" (passing props through many levels of components). It's ideal for accessing global data like user authentication status, themes, or language settings.
* **useReducer:** Often preferred over useState for more complex state logic or when the next state depends on the previous one. It is useful in scenarios with multiple state variables or intricate state transitions, such as managing a shopping cart or game state.
* **useRef:** This hook allows you to create a mutable value that persists across re-renders without causing the component to update. It is commonly used to access and interact with DOM elements directly or to store any mutable value that should not trigger a re-render.
* **useMemo and useCallback:** These performance optimization hooks are used to memoize (cache) values and functions, respectively. They help prevent unnecessary re-computations or re-creations of functions, which can improve performance in large applications by avoiding excessive re-renders of child components. 
# State management tools to be used in frontend development
## General & Framework-Agnostic Tools
### Redux (with Redux Toolkit): 
One of the most widely adopted solutions, Redux provides a centralized store and a predictable, unidirectional data flow, making it ideal for large-scale enterprise applications with complex state interactions. Redux Toolkit (RTK) was introduced to simplify boilerplate and configuration.
### MobX: 
MobX uses reactive programming principles and observables, automatically tracking changes and updating components. It is often praised for less boilerplate code and ease of use, making it suitable for small to medium-sized projects.
### RxJS Subjects: 
Often used in Angular development, RxJS allows managing state using reactive programming concepts and observable streams, particularly for low to medium-complexity applications. 

## Framework-Specific & Modern Tools
### React
**Built-in Hooks (useState, useReducer):** These allow for managing local component state and complex state logic, respectively, without adding external dependencies.
**Context API:** A built-in feature for sharing state across components without "prop drilling". It works well for simple global state needs like themes or user authentication but can cause performance issues in large applications if overused.
**Zustand:** A lightweight, fast, and scalable library with a simple, hook-based API that eliminates the need for a Provider wrapper. It's a popular choice for small to mid-size projects.
**Recoil & Jotai:** These libraries use an "atomic" approach where state is broken into small, independent units (atoms), enabling fine-grained updates and seamless integration with React's concurrent features like Suspense.
**Server State Libraries (React Query/TanStack Query, SWR):** These are specialized tools for fetching, caching, and synchronizing server data, effectively separating server state from client-side state. 

### Vue
**Vuex:** The official state management library for Vue, providing a centralized store and a structured pattern similar to Redux.

# How do you integrate REST APIs in react applications?
Integrating REST APIs in React applications typically involves using useState and useEffect hooks for managing data fetching, loading, and error states within functional components. You can use the built-in Fetch API or a library like Axios to make the HTTP requests. 

Core Steps for API Integration
Here is a step-by-step guide on fetching data using the built-in fetch API:
Set up state variables: Use the useState hook to store the fetched data, handle loading status, and manage potential errors.
```javascript
import React, { useState, useEffect } from 'react';

function App() {
  const [data, setData] = useState(null);
  const [isLoading, setIsLoading] = useState(false);
  const [error, setError] = useState(null);
  // ...
}
```
Use the useEffect hook: Wrap the API call within useEffect to perform the side effect after the component mounts. An empty dependency array ([]) ensures the call runs only once.
```javascript
// ... inside the App component
  useEffect(() => {
    // ... API logic here
  }, []);
```
Make the API call: Use fetch (or Axios) inside an async function and use await for asynchronous operations.
```javascript
// ... inside the useEffect hook
    const fetchData = async () => {
      setError(null);
      setIsLoading(true);
      try {
        const response = await fetch('https://api.example.com/data');
        if (!response.ok) {
          throw new Error('Failed to fetch data');
        }
        const json = await response.json();
        setData(json);
      } catch (err) {
        setError(err.message);
      } finally {
        setIsLoading(false);
      }
    };

    fetchData();
// ...
```
Render the data and states: In your component's return statement, conditionally render the data, a loading message, or an error message based on the state variables.
```javascript
// ... inside the App component return statement
  return (
    <div>
      <h2>API Data Display</h2>
      {isLoading && <p>Loading...</p>}
      {error && <p style={{ color: 'red' }}>Error: {error}</p>}
      {data && (
        <ul>
          {/* Example: map over data and display */}
          {/* {data.map(item => <li key={item.id}>{item.name}</li>)} */}
        </ul>
      )}
    </div>
  );
// ...
```

Tools for API Integration
Method 	Description	Pros	Cons
Fetch API	A built-in browser web API for making HTTP requests.	No extra installation needed, modern, promise-based.	Requires manual JSON parsing, error handling needs an explicit check on the response.ok property.
Axios	A popular, promise-based HTTP client library.	Automatic JSON data transformation, better error handling, can intercept requests/responses.	Requires installation (npm install axios).
Data Fetching Libraries	Libraries like React Query or SWR	Built-in caching, background re-fetching, and synchronization capabilities for complex apps.	Added complexity and a larger learning curve.
Best Practices
Separate Concerns: Abstract your API calls into a separate service file to keep components clean and focused on UI logic.
Handle All States: Always manage the loading, error, and success states to provide a good user experience.
Use Environment Variables: Store sensitive information like API keys in environment variables to avoid hardcoding them.
Implement Error Boundaries: Use a global error boundary to catch and handle
**Pinia:** A newer, more lightweight and intuitive state management solution that has become the recommended choice for Vue 3 projects. 

### Angular
**NgRx (Store):** Inspired by Redux, NgRx is the standard solution for managing complex state in Angular applications, following a similar pattern of actions, reducers, and a store.
**Services & Signals:** Angular's built-in dependency injection system allows using services for managing state, and the newer signals feature offers a way to create reactive, local state variables. 

# Which UI component libraries to use in react ?
# Frontend Performance optimization
Core Performance Techniques
Image Optimization: Compress images, use modern formats (WebP/AVIF), and implement responsive images (srcset).
Code Splitting & Bundling: Divide JavaScript bundles into smaller chunks to load only necessary code, reducing initial load time.
Lazy Loading: Defer loading non-critical resources (images, iframes, off-screen content) until needed.
Minification & Compression: Minify CSS, JavaScript, and HTML using tools like Terser; use Gzip or Brotli compression.
Browser Caching & CDN: Use Content Delivery Networks (CDNs) for faster asset delivery and configure cache headers to store resources locally.
Critical Rendering Path: Inline critical CSS and defer non-essential JavaScript to render the above-the-fold content faster. 
ByteByteGo
ByteByteGo
 +6
Tools to Measure Performance
Lighthouse (in Chrome DevTools): Audits performance, accessibility, and SEO.
Web Vitals: Measure real-world user experience (LCP, FID, CLS).
PageSpeed Insights: Analyzes content and provides optimization suggestions. 
Learn to Code — For Free
Learn to Code — For Free
 +3
Key Metrics to Monitor
Largest Contentful Paint (LCP): Measures loading performance (aim for < 2.5s).
First Input Delay (FID): Measures interactivity.
Cumulative Layout Shift (CLS): Measures visual stability. 
Strapi
Strapi
 +3
Effective frontend optimization is crucial because a 100-millisecond delay can reduce conversion rates. 
YouTube
YouTube
